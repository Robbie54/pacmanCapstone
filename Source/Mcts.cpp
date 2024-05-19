
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

Mcts::Mcts(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map) : map(map) {}

//mcts func 
int Mcts::selection(Position pacmanPosition, std::array<Position, 4> ghostPositions){
    Position pacmanGridPos; 
    pacmanGridPos.x = pacmanPosition.x/CELL_SIZE;
    pacmanGridPos.y = pacmanPosition.y/CELL_SIZE;
    

    int pathLengths = 1000; 
    move = 0;
    //check which squares are free 
    for(int i = 0; i < 4; i++){
        if(availableMoves[i] == true){
            int path = getShortestPathDistance(pacmanPosition + directions[i], ghostPositions[0]);
            if(path < pathLengths) { 
                pathLengths = path;
                move = i; 
            }
             
        }
    }

    std::cout << "Best path is " << move << " "; 
    // if(map[pacmanGridPos.x][pacmanGridPos.y] == 3 || map[pacmanGridPos.x][pacmanGridPos.y+1] == 1){ //down
    //         std::cout << "Hi " << map[pacmanGridPos.x][pacmanGridPos.y+1] << std::endl;
    // }

    return move;

}

bool Mcts::checkIfJunction(Position pos){
    //what if it comes to a corner before a junction 
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
                    // std::cout << "count " << neighbor.x << " " << neighbor.y << " The cell is: " << map[neighbor.x][neighbor.y] << " moves " << i << std::endl;
                    availableMoves[i] = true;
                    count++;
                }

            if(count >= 3){
                // std::cout << "its a junction " << count << std::endl;
                return true;
            }      
    }
    return false; 
}

bool Mcts::checkIfCorner(Position pos){
    //what if it comes to a corner before a junction 
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
                    // std::cout << "count " << neighbor.x << " " << neighbor.y << " The cell is: " << map[neighbor.x][neighbor.y] << " moves " << i << std::endl;
                    availableMoves[i] = true;
                    count++;
                }

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

                // std::cout << " hi " << std::endl;

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