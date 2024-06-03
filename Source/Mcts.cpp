
#include <array>
#include <vector>
#include <queue>
#include <cmath>

#include <iostream>


#include <SFML/Graphics.hpp>
#include "Headers/Global.hpp"

#include "Headers/Mcts.hpp"
#include "Headers/Pacman.hpp"
#include "Headers/Ghost.hpp"
#include "Headers/GhostManager.hpp"



using namespace std;


// queue<MCTS_move *> *MctsPacman_state::actions_to_try() const {
//     queue<MCTS_move *> *Q = new queue<MCTS_move *>();
//     //need pacman pos 
//     //and map positions
//     //and ghost positions
        
//             Q->push(new MctsPacman_move(gridPosX, gridPosY));
        
//     return Q;
// }


// MctsPacman_state::MctsPacman_state() : MCTS_state() {}


//copy constructor 
MctsPacman_state::MctsPacman_state(const MctsPacman_state &other) : MCTS_state(other), pacmanCurrentGridPos(other.pacmanCurrentGridPos), ghostCurrentGridPositions(other.ghostCurrentGridPositions), map(other.map) {

}

//initialise constructor 
MctsPacman_state::MctsPacman_state(const Position pacmanCurrentGridPos, const std::array<Position, 4> ghostCurrentGridPositions, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map)
    : MCTS_state(), pacmanCurrentGridPos(pacmanCurrentGridPos), ghostCurrentGridPositions(ghostCurrentGridPositions), map(map) {
    // Additional initialization code if needed
}

queue<MCTS_move *> *MctsPacman_state::actions_to_try() const {
    queue<MCTS_move *> *Q = new queue<MCTS_move *>();
    array<bool,4> moves = getAvaliableMoves();

    //add to the queue moves 
    for(int i = 0; i < moves.size(); i++){
        if(moves[i] == true){
            Q->push(new MctsPacman_move(pacmanCurrentGridPos.x + directions[i].x, pacmanCurrentGridPos.y + directions[i].y));
        }
    }

    return Q; 
}



array<bool,4> MctsPacman_state::getAvaliableMoves() const{
    array<bool,4> availableMoves = {false, false, false, false};

    for (int i = 0; i < 4; ++i) {
        const auto& dir = directions[i];
            Position neighbor{
                static_cast<short>(pacmanCurrentGridPos.x + dir.x), 
                static_cast<short>(pacmanCurrentGridPos.y + dir.y)
            };

            // std::cout << "neighbor " << neighbor.x << " " << neighbor.y << std::endl;
            // std::cout << "map " << map[neighbor.y][neighbor.x] << std::endl;

            // Check boundaries and if the cell is passable (not an obstacle)
            if (neighbor.x >= 0 && neighbor.x < MAP_WIDTH && 
                neighbor.y >= 0 && neighbor.y < MAP_HEIGHT &&
                (map[neighbor.x][neighbor.y] != Cell::Wall))
                {                
                   availableMoves[i] = true;
  
                }       
    }

    return availableMoves;
}

MCTS_state *MctsPacman_state::next_state(const MCTS_move *move) const{
    MctsPacman_move *m = (MctsPacman_move * ) move; //this is a c style cast. If move doesn't actually point to a mctsPacman_move object, undefined behavior can occur.
    MctsPacman_state *new_state = new MctsPacman_state(*this);

    switch (new_state->map[m->gridPosX][m->gridPosY]) {//a different way to write an if kinda
        //perhaps next state updates pacman and ghost pos and map 
        case Cell::Empty: 
        case Cell::Pellet: //if pellet need to update map to be empty for pacman move 
        case Cell::Energizer: //same also needs to update ghost state 
            new_state->pacmanCurrentGridPos.x = m->gridPosX;
            new_state->pacmanCurrentGridPos.y = m->gridPosY;
            new_state->map[m->gridPosX][m->gridPosY] = Cell::Empty;
            break;
        case Cell::Door: 
            new_state->pacmanCurrentGridPos.x = m->gridPosX;
            new_state->pacmanCurrentGridPos.y = m->gridPosY;
            break;
        case Cell::Wall:
            cerr << "Warning: Illegal move (" << m->gridPosX << ", " << m->gridPosY << ")" << endl;
            cout << "see next state func not sure if cerr is working" << endl;
            break;
    }

    return new_state;
}

double MctsPacman_state::rollout() const{
    return 1; 
}


bool MctsPacman_state::is_terminal() const{
    //if pacmanPos == any ghost pos thats terminal 
    //also if a level is complete thats terminal 
    //quoridor uses a check_winner function //this allows you to check who won in rollout rather then just returning a bool that somone did 
    char winner = checkWinner(); 

    return winner == 'P' || winner == 'G';  
}

char MctsPacman_state::checkWinner() const {
    for(const auto ghostPos : ghostCurrentGridPositions){
        if(ghostPos == pacmanCurrentGridPos){
            return 'G';
        }
    }
    //I will want to speed this up in the future 
    //currenlty thinking of just having a pellet counter and decreasing each tiem one is removed 
    bool game_won = 1;
    for (const std::array<Cell, MAP_HEIGHT>& column : map) {
        for (const Cell& cell : column)
        {
            
            if (Cell::Pellet == cell) //And if at least one of them has a pellet.
            {
                game_won = 0; //The game is not yet won.

                break;
            }
        }

        if (0 == game_won)
        {
            break;
        }
    }

				
    if(game_won == 1){
        return 'P';
    }
    else {
        return ' ';
    }
}





Mcts::Mcts(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map) : map(map){}

//mcts func 
int Mcts::run(Position pacmanPosition, std::array<Position, 4> ghostPositions){
    pacmanCurrentGridPos.x = pacmanPosition.x/CELL_SIZE;
    pacmanCurrentGridPos.y = pacmanPosition.y/CELL_SIZE;

    std::array<Position, 4> ghostGridPositions; 
    for(int i = 0; i <ghostGridPositions.size(); i++){
        ghostGridPositions[i].x = ghostPositions[i].x/CELL_SIZE;
        ghostGridPositions[i].y = ghostPositions[i].y/CELL_SIZE;
    }
    
    bool done; 

    MCTS_state *state = new MctsPacman_state(pacmanCurrentGridPos, ghostGridPositions, map); 
    //

    
    int pathLengths = INT32_MAX; 

    move = -1;
    //available moves should be right, up left , down . 0  1 2 3 
    int oppositeDirection[] = {2, 3, 0, 1}; // For directions 0, 1, 2, 3 respectively
    //check which squares are free 
   if(checkIfJunction(pacmanPosition) || checkIfCorner(pacmanPosition)){
        for(int i = 0; i < 4; i++){
            if(availableMoves[i] == true ){
                int path = getShortestPathDistance(pacmanPosition + directions[i], ghostPositions[0]);
                if(path < pathLengths) { 
                    pathLengths = path;
                    move = i; 
                } 
            }
        }
   }
   

    // std::cout << "Best path is " << move << " "; 
    // if(map[pacmanGridPos.x][pacmanGridPos.y] == 3 || map[pacmanGridPos.x][pacmanGridPos.y+1] == 1){ //down
    //         std::cout << "Hi " << map[pacmanGridPos.x][pacmanGridPos.y+1] << std::endl;
    // }

    return move;

}

bool Mcts::checkIfJunction(Position pos){
    //what if it comes to a corner before a junction 
    int count = updateAvailableMoves(pos);

            if(count >= 3){
                // std::cout << "its a junction " << count << std::endl;
                return true;
            }      
    
    return false; 
}

bool Mcts::checkIfCorner(Position pos){
    //what if it comes to a corner before a junction 
     updateAvailableMoves(pos);

           for(int i =0; i<availableMoves.size()-1; i++){
                if(availableMoves[i] && availableMoves[i+1]){
                    std::cout << "available moves are " << i << " and " << i+1 << std::endl;
                    return true;
                }
           }   

           if(availableMoves[3] && availableMoves[0]) { 
            std::cout << "available moves are " << 3 << " and " << 0<< std::endl;
            return true;
            }

    
    return false; 
}


int Mcts::cornerMove(){
    for(int i = 0; i<4; i++){
        if(availableMoves[i]){
            if(move != i){
                return i;
            }
        }
    }
    return -1;
}

int Mcts::getShortestPathDistance(Position pos, Position pos2){
    //pos is pacman 
    return getShortestPath(pos, pos2).size();
}




//sometimes the pos is in a wall sometimes its just 0

std::vector<Position> Mcts::getShortestPath(Position pos, Position pos2){
    std::vector<Position> path; 

    //initialise in gridPos format 
    Position gridPos; 
    gridPos.x = pos.x/CELL_SIZE ;
    gridPos.y  = pos.y/CELL_SIZE ;

    Position gridPos2;
    gridPos2.x = pos2.x/CELL_SIZE;
    gridPos2.y = pos2.y/CELL_SIZE;

    if (gridPos == gridPos2) {
        // std::cout << "Positions are the same. 0 distance" << std::endl;

        return path;
    }


    if (map[gridPos.x][gridPos.y] == Cell::Wall) {
        std::cout << "Pacman is in a wall." << gridPos.x << " " << gridPos.y << std::endl;
        return path; // Return an empty path
    }
    if (map[gridPos.x][gridPos.y] == Cell::Wall) {
        std::cout << "red ghost is in a wall." << std::endl;
        return path; // Return an empty path
    }

    // std::cout << "Pos 1 " << gridPos.x << " " << gridPos.y << std::endl;
    // std::cout << "Pos 2 " << gridPos2.x << " " << gridPos2.y << std::endl;


    std::queue<Position> queue;
    std::map<Position, Position> came_from;
    std::map<Position, bool> visited;

    

    // Start BFS from the initial position
    queue.push(gridPos);
    visited[gridPos] = true;

    bool found = false;
    while (!queue.empty() && !found) {
         
        Position current = queue.front();
        queue.pop();

        for (const auto& dir : directions) {
            Position neighbor{
                static_cast<short>(current.x + dir.x), 
                static_cast<short>(current.y + dir.y)
            };

            // std::cout << "neighbor " << neighbor.x << " " << neighbor.y << std::endl;
            // std::cout << "map " << map[neighbor.y][neighbor.x] << std::endl;
 
 
            // Check boundaries and if the cell is passable (not an obstacle)
            if (neighbor.x >= 0 && neighbor.x < MAP_WIDTH && 
                neighbor.y >= 0 && neighbor.y < MAP_HEIGHT &&
                // (map[neighbor.y][neighbor.x] == 1 || map[neighbor.y][neighbor.x] == 3 || map[neighbor.y][neighbor.x] == 2)
                (map[neighbor.x][neighbor.y] != Cell::Wall) 
                && !visited[neighbor]) {

                queue.push(neighbor);
                visited[neighbor] = true;
                came_from[neighbor] = current;

                // Check if we've reached the destination
                if (neighbor == gridPos2) {
                    found = true;
                    break;
                }
            }
        }
    }

    if (found) {
        // Build the path by backtracking from the destination
        for (Position step = gridPos2; step != gridPos; step = came_from[step]) {
            // std::cout << "THe path is " << step.x << " " << step.y << std::endl;
            path.push_back(step);
        }
        // std::cout << std::endl;
        path.push_back(gridPos);
        std::reverse(path.begin(), path.end());
    }

    // if(path.size() == 0){
    //     while(0 == sf::Keyboard::isKeyPressed(sf::Keyboard::S)){};
    // }
return path;

}


// selection
// expansion 
// rollout 
// backpropogation


int Mcts::updateAvailableMoves(Position pos){
    int count = 0;
    Position gridPos; 
    gridPos.x = pos.x/CELL_SIZE;
    gridPos.y  = pos.y/CELL_SIZE;

    availableMoves = {false, false, false, false};

    for (int i = 0; i < directions.size(); ++i) {
            const auto& dir = directions[i];
                Position neighbor{
                    static_cast<short>(gridPos.x + dir.x), 
                    static_cast<short>(gridPos.y + dir.y)
                };

                // std::cout << "neighbor " << neighbor.x << " " << neighbor.y << std::endl;
                // std::cout << "map " << map[neighbor.y][neighbor.x] << std::endl;

                // Check boundaries and if the cell is passable (not an obstacle)
                if (neighbor.x >= 0 && neighbor.x < MAP_WIDTH && 
                    neighbor.y >= 0 && neighbor.y < MAP_HEIGHT &&
                    (map[neighbor.x][neighbor.y] != Cell::Wall))
                    {
                        //availible moves in here 
                        // std::cout << "count " << neighbor.x << " " << neighbor.y << " The cell is: " << map[neighbor.x][neighbor.y] << std::endl;
                        int a = 0; //right
                        //need to convert moves to pacman relative
                        //available moves should be right, up left , down . 0  1 2 3 
                        if(i == 1){
                            a = 2; //left
                        }
                        else if(i == 2){
                            a = 3;
                        }
                        else if(i == 3){
                            a = 1;
                        }
                        availableMoves[a] = true;
                        count++;
                        
                    }       
    }

    return count;
}