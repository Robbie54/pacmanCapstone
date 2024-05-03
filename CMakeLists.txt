cmake_minimum_required(VERSION 3.0.0)
project(Main VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


# Find SFML shared libraries
find_package(SFML 2.5 REQUIRED graphics window system)

# Include the directories for SFML
include_directories(${SFML_INCLUDE_DIR})

add_executable(Main Source/Main.cpp Source/ConvertSketch.cpp Source/DrawMap.cpp Source/DrawText.cpp Source/Ghost.cpp Source/GhostManager.cpp Source/MapCollision.cpp Source/Pacman.cpp Source/Mcts.cpp)

target_link_libraries(Main sfml-graphics sfml-window sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
