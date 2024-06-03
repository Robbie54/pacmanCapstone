#pragma once 



//derived classes need parent file path in .h file not cpp
#include "../../MonteCarloTreeSearch-main/mcts/include/state.h"




/* 
state class 
- needs the state of map walls, pellets , energizers, ghosts and pacman

*/
class MctsPacman_state : public MCTS_state{
    private:
        Position pacmanCurrentGridPos;
        std::array<Position, 4> ghostCurrentGridPositions;
        std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map;

        //right //up //left //down 
        std::array<Position, 4> directions = {{{1, 0}, {0, 1}, {-1, 0}, {-1, 0}}}; 



    //functions to consider 
    //pacman.get_dead // is pacman alive? //kinda like is_terminal
    //

	public: 
        // MctsPacman_state(); //default constructor can initialise board 
        MctsPacman_state(const MctsPacman_state &other); //constructor to initialise using another state
        MctsPacman_state(const Position pacmanCurrentGridPos, const std::array<Position, 4> ghostCurrentGridPositions, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map);


        /**
         * @brief creates a queue of all available moves to pacman essentially getting available moves
         * @return a queue of MCts_move objects 
        */
        queue<MCTS_move *> *actions_to_try() const override;

        /**
         * @brief  get available moves for pacman in current pos 
         * Not sure if its needed currenlty only actions to try uses it could just put in there 
         * @return moves in bool format - right(0), up(1), left(2), down(3) 
        */
       
        std::array<bool, 4> getAvaliableMoves() const; 

        /**
         * @brief gets the next state of the game updating pacman and ghosts by one position with mcts_move 
         * @todo probally need to add ghost positions to mcts_move 
         * @return returns tne next state so pacman, ghost positions and map updates 
         * */ 

        MCTS_state *next_state(const MCTS_move *move) const override;
        
        double rollout() const override;
        bool is_terminal() const override;

        
        /**
         * @brief checks if either ghost has won or pacman has cleared level 
         * @todo implement 
         * @return 'P' for pacman complete level, 'G' for ghost hit pacman and ' ' no win
        */
        char checkWinner() const;

        //only here bc its pure virtual not sure if i need it at all 
        bool player1_turn() const {
            return true; 
        };   

};



struct MctsPacman_move : public MCTS_move { 
    
    //permove might also need the ghost positions 

    int gridPosX; 
    int gridPosY;

	MctsPacman_move(int x, int y) : gridPosX(x), gridPosY(y) {};
	bool operator==(const MCTS_move& other) const override {
        const MctsPacman_move &o = (const MctsPacman_move&) other;
        return gridPosX == o.gridPosX && gridPosX == o.gridPosY;
    }  
};



class Mcts {

    
    enum Direction {
        Up,
        Down,
        Right,
        Left
    };

    int move;

    Position pacmanCurrentGridPos; 


    // Directions for moving in the grid //this is old
    std::array<Position, 4> directions = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}}; //right //left //down //up 
    // std::array<Position, 4> directions = {{{1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    std::array<bool, 4> availableMoves; //copying pacman moves 
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};
    
    public:
        Mcts(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map);



        //currenlty map is just static for each runthough
        int run(Position pacmanPosition, std::array<Position, 4> ghostPositions);
        

        //distance from one square to another //might be useful to implement a euclid and manhattan distance 
        int getShortestPathDistance(Position pos, Position pos2);

        //path from one square to another 
        std::vector<Position> getShortestPath(Position pos, Position pos2);

        bool checkIfJunction(Position pos);
        bool checkIfCorner(Position pos);
        int cornerMove();

        //old (in state now)
        int updateAvailableMoves(Position pos);

};


//Hunt edible ghosts if not far away //i like this idea also need a get shortest path func 
		// for(GHOST ghost : GHOST.values()) {
		// 	if(game.getGhostEdibleTime(ghost) > 0) {
		// 		if(game.getShortestPathDistance(game.getPacmanCurrentNodeIndex(),game.getGhostCurrentNodeIndex(ghost)) < hunt_dist) {
		// 			return game.getNextMoveTowardsTarget(game.getPacmanCurrentNodeIndex(),game.getGhostCurrentNodeIndex(ghost), DM.PATH);
		// 		}
		// 	}
		// }