# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/175/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/175/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexey/_1_treasure_island_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexey/_1_treasure_island_game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/Server/srcServer/main.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Server/srcServer/main.cpp.o: ../Server/srcServer/main.cpp
CMakeFiles/Server.dir/Server/srcServer/main.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/Server/srcServer/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/Server/srcServer/main.cpp.o -MF CMakeFiles/Server.dir/Server/srcServer/main.cpp.o.d -o CMakeFiles/Server.dir/Server/srcServer/main.cpp.o -c /home/alexey/_1_treasure_island_game/Server/srcServer/main.cpp

CMakeFiles/Server.dir/Server/srcServer/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Server/srcServer/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/_1_treasure_island_game/Server/srcServer/main.cpp > CMakeFiles/Server.dir/Server/srcServer/main.cpp.i

CMakeFiles/Server.dir/Server/srcServer/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Server/srcServer/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/_1_treasure_island_game/Server/srcServer/main.cpp -o CMakeFiles/Server.dir/Server/srcServer/main.cpp.s

CMakeFiles/Server.dir/EventBus/EventBus.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/EventBus/EventBus.cpp.o: ../EventBus/EventBus.cpp
CMakeFiles/Server.dir/EventBus/EventBus.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.dir/EventBus/EventBus.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/EventBus/EventBus.cpp.o -MF CMakeFiles/Server.dir/EventBus/EventBus.cpp.o.d -o CMakeFiles/Server.dir/EventBus/EventBus.cpp.o -c /home/alexey/_1_treasure_island_game/EventBus/EventBus.cpp

CMakeFiles/Server.dir/EventBus/EventBus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/EventBus/EventBus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/_1_treasure_island_game/EventBus/EventBus.cpp > CMakeFiles/Server.dir/EventBus/EventBus.cpp.i

CMakeFiles/Server.dir/EventBus/EventBus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/EventBus/EventBus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/_1_treasure_island_game/EventBus/EventBus.cpp -o CMakeFiles/Server.dir/EventBus/EventBus.cpp.s

CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o: ../Server/srcServer/Player.cpp
CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o -MF CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o.d -o CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o -c /home/alexey/_1_treasure_island_game/Server/srcServer/Player.cpp

CMakeFiles/Server.dir/Server/srcServer/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Server/srcServer/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/_1_treasure_island_game/Server/srcServer/Player.cpp > CMakeFiles/Server.dir/Server/srcServer/Player.cpp.i

CMakeFiles/Server.dir/Server/srcServer/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Server/srcServer/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/_1_treasure_island_game/Server/srcServer/Player.cpp -o CMakeFiles/Server.dir/Server/srcServer/Player.cpp.s

CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o: ../Server/srcServer/Model.cpp
CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o -MF CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o.d -o CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o -c /home/alexey/_1_treasure_island_game/Server/srcServer/Model.cpp

CMakeFiles/Server.dir/Server/srcServer/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/Server/srcServer/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/_1_treasure_island_game/Server/srcServer/Model.cpp > CMakeFiles/Server.dir/Server/srcServer/Model.cpp.i

CMakeFiles/Server.dir/Server/srcServer/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/Server/srcServer/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/_1_treasure_island_game/Server/srcServer/Model.cpp -o CMakeFiles/Server.dir/Server/srcServer/Model.cpp.s

CMakeFiles/Server.dir/EventBus/Event.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/EventBus/Event.cpp.o: ../EventBus/Event.cpp
CMakeFiles/Server.dir/EventBus/Event.cpp.o: CMakeFiles/Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Server.dir/EventBus/Event.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Server.dir/EventBus/Event.cpp.o -MF CMakeFiles/Server.dir/EventBus/Event.cpp.o.d -o CMakeFiles/Server.dir/EventBus/Event.cpp.o -c /home/alexey/_1_treasure_island_game/EventBus/Event.cpp

CMakeFiles/Server.dir/EventBus/Event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/EventBus/Event.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/_1_treasure_island_game/EventBus/Event.cpp > CMakeFiles/Server.dir/EventBus/Event.cpp.i

CMakeFiles/Server.dir/EventBus/Event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/EventBus/Event.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/_1_treasure_island_game/EventBus/Event.cpp -o CMakeFiles/Server.dir/EventBus/Event.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/Server/srcServer/main.cpp.o" \
"CMakeFiles/Server.dir/EventBus/EventBus.cpp.o" \
"CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o" \
"CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o" \
"CMakeFiles/Server.dir/EventBus/Event.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/Server/srcServer/main.cpp.o
Server: CMakeFiles/Server.dir/EventBus/EventBus.cpp.o
Server: CMakeFiles/Server.dir/Server/srcServer/Player.cpp.o
Server: CMakeFiles/Server.dir/Server/srcServer/Model.cpp.o
Server: CMakeFiles/Server.dir/EventBus/Event.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: /usr/lib/x86_64-linux-gnu/libsfml-system.so
Server: /usr/lib/x86_64-linux-gnu/libsfml-window.so
Server: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
Server: /usr/lib/x86_64-linux-gnu/libsfml-network.so
Server: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server
.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/alexey/_1_treasure_island_game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/_1_treasure_island_game /home/alexey/_1_treasure_island_game /home/alexey/_1_treasure_island_game/cmake-build-debug /home/alexey/_1_treasure_island_game/cmake-build-debug /home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

