# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robbie/Desktop/Capstone/pacmanCapstone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robbie/Desktop/Capstone/pacmanCapstone/build

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/Source/Main.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/Main.cpp.o: ../Source/Main.cpp
CMakeFiles/Main.dir/Source/Main.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.dir/Source/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/Main.cpp.o -MF CMakeFiles/Main.dir/Source/Main.cpp.o.d -o CMakeFiles/Main.dir/Source/Main.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Main.cpp

CMakeFiles/Main.dir/Source/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Main.cpp > CMakeFiles/Main.dir/Source/Main.cpp.i

CMakeFiles/Main.dir/Source/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Main.cpp -o CMakeFiles/Main.dir/Source/Main.cpp.s

CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o: ../Source/ConvertSketch.cpp
CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o -MF CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o.d -o CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/ConvertSketch.cpp

CMakeFiles/Main.dir/Source/ConvertSketch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/ConvertSketch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/ConvertSketch.cpp > CMakeFiles/Main.dir/Source/ConvertSketch.cpp.i

CMakeFiles/Main.dir/Source/ConvertSketch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/ConvertSketch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/ConvertSketch.cpp -o CMakeFiles/Main.dir/Source/ConvertSketch.cpp.s

CMakeFiles/Main.dir/Source/DrawMap.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/DrawMap.cpp.o: ../Source/DrawMap.cpp
CMakeFiles/Main.dir/Source/DrawMap.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Main.dir/Source/DrawMap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/DrawMap.cpp.o -MF CMakeFiles/Main.dir/Source/DrawMap.cpp.o.d -o CMakeFiles/Main.dir/Source/DrawMap.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/DrawMap.cpp

CMakeFiles/Main.dir/Source/DrawMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/DrawMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/DrawMap.cpp > CMakeFiles/Main.dir/Source/DrawMap.cpp.i

CMakeFiles/Main.dir/Source/DrawMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/DrawMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/DrawMap.cpp -o CMakeFiles/Main.dir/Source/DrawMap.cpp.s

CMakeFiles/Main.dir/Source/DrawText.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/DrawText.cpp.o: ../Source/DrawText.cpp
CMakeFiles/Main.dir/Source/DrawText.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Main.dir/Source/DrawText.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/DrawText.cpp.o -MF CMakeFiles/Main.dir/Source/DrawText.cpp.o.d -o CMakeFiles/Main.dir/Source/DrawText.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/DrawText.cpp

CMakeFiles/Main.dir/Source/DrawText.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/DrawText.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/DrawText.cpp > CMakeFiles/Main.dir/Source/DrawText.cpp.i

CMakeFiles/Main.dir/Source/DrawText.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/DrawText.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/DrawText.cpp -o CMakeFiles/Main.dir/Source/DrawText.cpp.s

CMakeFiles/Main.dir/Source/Ghost.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/Ghost.cpp.o: ../Source/Ghost.cpp
CMakeFiles/Main.dir/Source/Ghost.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Main.dir/Source/Ghost.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/Ghost.cpp.o -MF CMakeFiles/Main.dir/Source/Ghost.cpp.o.d -o CMakeFiles/Main.dir/Source/Ghost.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Ghost.cpp

CMakeFiles/Main.dir/Source/Ghost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/Ghost.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Ghost.cpp > CMakeFiles/Main.dir/Source/Ghost.cpp.i

CMakeFiles/Main.dir/Source/Ghost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/Ghost.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Ghost.cpp -o CMakeFiles/Main.dir/Source/Ghost.cpp.s

CMakeFiles/Main.dir/Source/GhostManager.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/GhostManager.cpp.o: ../Source/GhostManager.cpp
CMakeFiles/Main.dir/Source/GhostManager.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Main.dir/Source/GhostManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/GhostManager.cpp.o -MF CMakeFiles/Main.dir/Source/GhostManager.cpp.o.d -o CMakeFiles/Main.dir/Source/GhostManager.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/GhostManager.cpp

CMakeFiles/Main.dir/Source/GhostManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/GhostManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/GhostManager.cpp > CMakeFiles/Main.dir/Source/GhostManager.cpp.i

CMakeFiles/Main.dir/Source/GhostManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/GhostManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/GhostManager.cpp -o CMakeFiles/Main.dir/Source/GhostManager.cpp.s

CMakeFiles/Main.dir/Source/MapCollision.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/MapCollision.cpp.o: ../Source/MapCollision.cpp
CMakeFiles/Main.dir/Source/MapCollision.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Main.dir/Source/MapCollision.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/MapCollision.cpp.o -MF CMakeFiles/Main.dir/Source/MapCollision.cpp.o.d -o CMakeFiles/Main.dir/Source/MapCollision.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/MapCollision.cpp

CMakeFiles/Main.dir/Source/MapCollision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/MapCollision.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/MapCollision.cpp > CMakeFiles/Main.dir/Source/MapCollision.cpp.i

CMakeFiles/Main.dir/Source/MapCollision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/MapCollision.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/MapCollision.cpp -o CMakeFiles/Main.dir/Source/MapCollision.cpp.s

CMakeFiles/Main.dir/Source/Pacman.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/Pacman.cpp.o: ../Source/Pacman.cpp
CMakeFiles/Main.dir/Source/Pacman.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Main.dir/Source/Pacman.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/Pacman.cpp.o -MF CMakeFiles/Main.dir/Source/Pacman.cpp.o.d -o CMakeFiles/Main.dir/Source/Pacman.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Pacman.cpp

CMakeFiles/Main.dir/Source/Pacman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/Pacman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Pacman.cpp > CMakeFiles/Main.dir/Source/Pacman.cpp.i

CMakeFiles/Main.dir/Source/Pacman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/Pacman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Pacman.cpp -o CMakeFiles/Main.dir/Source/Pacman.cpp.s

CMakeFiles/Main.dir/Source/Mcts.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Source/Mcts.cpp.o: ../Source/Mcts.cpp
CMakeFiles/Main.dir/Source/Mcts.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Main.dir/Source/Mcts.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/Source/Mcts.cpp.o -MF CMakeFiles/Main.dir/Source/Mcts.cpp.o.d -o CMakeFiles/Main.dir/Source/Mcts.cpp.o -c /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Mcts.cpp

CMakeFiles/Main.dir/Source/Mcts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Source/Mcts.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Mcts.cpp > CMakeFiles/Main.dir/Source/Mcts.cpp.i

CMakeFiles/Main.dir/Source/Mcts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Source/Mcts.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robbie/Desktop/Capstone/pacmanCapstone/Source/Mcts.cpp -o CMakeFiles/Main.dir/Source/Mcts.cpp.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/Source/Main.cpp.o" \
"CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o" \
"CMakeFiles/Main.dir/Source/DrawMap.cpp.o" \
"CMakeFiles/Main.dir/Source/DrawText.cpp.o" \
"CMakeFiles/Main.dir/Source/Ghost.cpp.o" \
"CMakeFiles/Main.dir/Source/GhostManager.cpp.o" \
"CMakeFiles/Main.dir/Source/MapCollision.cpp.o" \
"CMakeFiles/Main.dir/Source/Pacman.cpp.o" \
"CMakeFiles/Main.dir/Source/Mcts.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main: CMakeFiles/Main.dir/Source/Main.cpp.o
Main: CMakeFiles/Main.dir/Source/ConvertSketch.cpp.o
Main: CMakeFiles/Main.dir/Source/DrawMap.cpp.o
Main: CMakeFiles/Main.dir/Source/DrawText.cpp.o
Main: CMakeFiles/Main.dir/Source/Ghost.cpp.o
Main: CMakeFiles/Main.dir/Source/GhostManager.cpp.o
Main: CMakeFiles/Main.dir/Source/MapCollision.cpp.o
Main: CMakeFiles/Main.dir/Source/Pacman.cpp.o
Main: CMakeFiles/Main.dir/Source/Mcts.cpp.o
Main: CMakeFiles/Main.dir/build.make
Main: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
Main: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
Main: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
Main: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: Main
.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd /home/robbie/Desktop/Capstone/pacmanCapstone/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robbie/Desktop/Capstone/pacmanCapstone /home/robbie/Desktop/Capstone/pacmanCapstone /home/robbie/Desktop/Capstone/pacmanCapstone/build /home/robbie/Desktop/Capstone/pacmanCapstone/build /home/robbie/Desktop/Capstone/pacmanCapstone/build/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main.dir/depend

