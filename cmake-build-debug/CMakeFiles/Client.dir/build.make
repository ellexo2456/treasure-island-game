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
include CMakeFiles/Client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/Client/srcClient/main.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Client/srcClient/main.cpp.o: ../Client/srcClient/main.cpp
CMakeFiles/Client.dir/Client/srcClient/main.cpp.o: CMakeFiles/Client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/Client/srcClient/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Client.dir/Client/srcClient/main.cpp.o -MF CMakeFiles/Client.dir/Client/srcClient/main.cpp.o.d -o CMakeFiles/Client.dir/Client/srcClient/main.cpp.o -c /home/alexey/_1_treasure_island_game/Client/srcClient/main.cpp

CMakeFiles/Client.dir/Client/srcClient/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Client/srcClient/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/_1_treasure_island_game/Client/srcClient/main.cpp > CMakeFiles/Client.dir/Client/srcClient/main.cpp.i

CMakeFiles/Client.dir/Client/srcClient/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Client/srcClient/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/_1_treasure_island_game/Client/srcClient/main.cpp -o CMakeFiles/Client.dir/Client/srcClient/main.cpp.s

CMakeFiles/Client.dir/EventBus/EventBus.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/EventBus/EventBus.cpp.o: ../EventBus/EventBus.cpp
CMakeFiles/Client.dir/EventBus/EventBus.cpp.o: CMakeFiles/Client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/EventBus/EventBus.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Client.dir/EventBus/EventBus.cpp.o -MF CMakeFiles/Client.dir/EventBus/EventBus.cpp.o.d -o CMakeFiles/Client.dir/EventBus/EventBus.cpp.o -c /home/alexey/_1_treasure_island_game/EventBus/EventBus.cpp

CMakeFiles/Client.dir/EventBus/EventBus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/EventBus/EventBus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/_1_treasure_island_game/EventBus/EventBus.cpp > CMakeFiles/Client.dir/EventBus/EventBus.cpp.i

CMakeFiles/Client.dir/EventBus/EventBus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/EventBus/EventBus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/_1_treasure_island_game/EventBus/EventBus.cpp -o CMakeFiles/Client.dir/EventBus/EventBus.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/Client/srcClient/main.cpp.o" \
"CMakeFiles/Client.dir/EventBus/EventBus.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/Client/srcClient/main.cpp.o
Client: CMakeFiles/Client.dir/EventBus/EventBus.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: /usr/lib/x86_64-linux-gnu/libsfml-system.so
Client: /usr/lib/x86_64-linux-gnu/libsfml-window.so
Client: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
Client: /usr/lib/x86_64-linux-gnu/libsfml-network.so
Client: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client
.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /home/alexey/_1_treasure_island_game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/_1_treasure_island_game /home/alexey/_1_treasure_island_game /home/alexey/_1_treasure_island_game/cmake-build-debug /home/alexey/_1_treasure_island_game/cmake-build-debug /home/alexey/_1_treasure_island_game/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend
