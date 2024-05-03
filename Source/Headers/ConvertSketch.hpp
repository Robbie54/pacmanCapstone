#pragma once
//This class takes teh ghosts positions, pacman positions and the map to return a map of all 
//literally sends an reference to the object of the pacman class  
//seems to be only called once to initialise game 
std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convert_sketch(const std::array<std::string, MAP_HEIGHT>& i_map_sketch, std::array<Position, 4>& i_ghost_positions, Pacman& i_pacman);