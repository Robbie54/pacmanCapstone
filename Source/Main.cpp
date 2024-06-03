#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "Headers/Global.hpp"
#include "Headers/DrawText.hpp"
#include "Headers/Pacman.hpp"
#include "Headers/Ghost.hpp"
#include "Headers/GhostManager.hpp"
#include "Headers/ConvertSketch.hpp"
#include "Headers/DrawMap.hpp"
#include "Headers/MapCollision.hpp"
#include "Headers/Mcts.hpp"

#include <iostream>

using std::cout;
using std::endl;


int main()
{
	//Is the game won?
	bool game_won = 0;

	//Used to make the game framerate-independent.
	unsigned lag = 0;

	unsigned char level = 0;

	//Similar to lag, used to make the game framerate-independent.
	std::chrono::time_point<std::chrono::steady_clock> previous_time;

	//It's not exactly like the map from the original Pac-Man game, but it's close enough.
	std::array<std::string, MAP_HEIGHT> map_sketch = {
		" ################### ",
		" #........#........# ",
		" #o##.###.#.###.##o# ",
		" #.................# ",
		" #.##.#.#####.#.##.# ",
		" #....#...#...#....# ",
		" ####.### # ###.#### ",
		"    #.#   0   #.#    ",
		"#####.# ##=## #.#####",
		"     .  #123#  .     ",
		"#####.# ##### #.#####",
		"    #.#       #.#    ",
		" ####.# ##### #.#### ",
		" #........#........# ",
		" #.##.###.#.###.##.# ",
		" #o.#.....P.....#.o# ",
		" ##.#.#.#####.#.#.## ",
		" #....#...#...#....# ",
		" #.######.#.######.# ",
		" #.................# ",
		" ################### "
	};

	//This is the map 
	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

	//Initial ghost positions.
	std::array<Position, 4> ghost_positions;

	//SFML thing. Stores events, I think.
	sf::Event event;

	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "Pac-Man", sf::Style::Close);
	//Resizing the window.
	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

	GhostManager ghost_manager;

	Pacman pacman;

	

	//Generating a random seed.
	srand(static_cast<unsigned>(time(0)));

	map = convert_sketch(map_sketch, ghost_positions, pacman);

	//initialised once map is made
	Mcts mcts(map);

	ghost_manager.reset(level, ghost_positions);

	//Get the current time and store it in a variable.
	previous_time = std::chrono::steady_clock::now();


//#################### Start Game loop ######################
	while (1 == window.isOpen())
	{

		//Here we're calculating the lag.
		unsigned delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();

		lag += delta_time;

		previous_time += std::chrono::microseconds(delta_time);

		//While the lag exceeds the maximum allowed frame duration.
		while (FRAME_DURATION <= lag)
		{
			//We decrease the lag.
			lag -= FRAME_DURATION;

			while (1 == window.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
					{
						//Making sure the player can close the window.
						window.close();
					}
				}
			}
			
			if (false == game_won && false == pacman.get_dead())
			{
				game_won = true;

				std::array<Position, 4> allGhostPos = ghost_manager.getAllPositions();

				//I want to run mcts here but im not sure if i should just use a function or make a class object
				int move = mcts.run(pacman.get_position(), allGhostPos);

				//checks for keyboard input
				
				// int move = pacman.keyboardMovement(); 

				//updates pacman position 
				
				std::cout << "pacman update moving " << move << std::endl;
			
				pacman.update(level, map, move);
				

				ghost_manager.update(level, map, pacman);

				//We're checking every cell in the map. To check if level is complete
				for (const std::array<Cell, MAP_HEIGHT>& column : map)
				{
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

				if (1 == game_won)
				{
					pacman.set_animation_timer(0);
				}
			}
			else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) //Restarting the game.
			{
				game_won = 0;

				if (1 == pacman.get_dead())
				{
					level = 0;
				}
				else
				{
					//After each win we reduce the duration of attack waves and energizers.
					level++;
				}

				
				//This only happens when game is being reset 
				map = convert_sketch(map_sketch, ghost_positions, pacman);

				ghost_manager.reset(level, ghost_positions);

				pacman.reset();
			}


			if (FRAME_DURATION > lag)
			{
				window.clear();

				if (game_won == false && false == pacman.get_dead())
				{
					
					draw_map(map, window); //draws the map 

					ghost_manager.draw(GHOST_FLASH_START >= pacman.get_energizer_timer(), window); //draws the ghosts 

					draw_text(0, 0, CELL_SIZE * MAP_HEIGHT, "Level "  + std::to_string(1 + level), window);
					
				}

				pacman.draw(game_won, window);	//draws pacman in game


				
	

				// std::cout << pacman.get_position().x/CELL_SIZE << " " << pacman.get_position().y/CELL_SIZE << std::endl;
					
				
				// for(int i = 0; i < 4; i++){
				// 	std::cout << "Ghost: " << i << " " << allGhostPos[i].x/CELL_SIZE << " " << allGhostPos[i].y/CELL_SIZE << std::endl;	
				// }	

					
					// std::vector<Position> p = mcts.getShortestPath(pacman.get_position(), allGhostPos[0]);
					
					
					
					// for(auto i : p){
					// 	map[i.x][i.y] = Marker;
					// }
				 	// draw_map(map,window);
				// mcts.selection(allGhostPos, pacman.get_position(), map);
				
				// std::cout << mcts.getShortestPathDistance(pacman.get_position(), allGhostPos[0]) << std::endl;

				


				if (1 == pacman.get_animation_over())
				{
					if (1 == game_won)
					{
						draw_text(1, 0, 0, "Next level!", window);
					}
					else
					{
						draw_text(1, 0, 0, "Game over", window);
					}
				}

				window.display();
			}
		}
	}
}