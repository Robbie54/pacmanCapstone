#pragma once 


//needs pacman positions 
//ghost positions 
//map -> availible moves, pellets left 

//I think the first thing to do is get available moves and move pacman as far away as possible from ghosts


//run mcts at each junction 
//follow path until chosen junction is met 

class Mcts {

    enum Direction {
        Up,
        Down,
        Right,
        Left
    };

    int move;

    // Directions for moving in the grid 
    std::array<Position, 4> directions = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}}; //right //left //down //up
    // std::array<Position, 4> directions = {{{1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    std::array<bool, 4> availableMoves; //1 is available //up right down left //currently reading like 0 is right 1 is left, 2 down, 3up
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};
    
    public:
        Mcts(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map);

        int selection(Position pacmanPosition, std::array<Position, 4> ghostPositions);
        

        //distance from one square to another //might be useful to implement a euclid and manhattan distance 
        int getShortestPathDistance(Position pos, Position pos2);

        //path from one square to another 
        std::vector<Position> getShortestPath(Position pos, Position pos2);

        bool checkIfJunction(Position pos);
        bool checkIfCorner(Position pos);
        int cornerMove();





};


//Hunt edible ghosts if not far away //i like this idea also need a get shortest path func 
		// for(GHOST ghost : GHOST.values()) {
		// 	if(game.getGhostEdibleTime(ghost) > 0) {
		// 		if(game.getShortestPathDistance(game.getPacmanCurrentNodeIndex(),game.getGhostCurrentNodeIndex(ghost)) < hunt_dist) {
		// 			return game.getNextMoveTowardsTarget(game.getPacmanCurrentNodeIndex(),game.getGhostCurrentNodeIndex(ghost), DM.PATH);
		// 		}
		// 	}
		// }