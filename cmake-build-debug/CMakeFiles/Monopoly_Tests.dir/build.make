# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/CLion/CLion-2024.2.0.1-aarch64/clion-2024.2.0.1/bin/cmake/linux/aarch64/bin/cmake

# The command to remove a file.
RM = /opt/CLion/CLion-2024.2.0.1-aarch64/clion-2024.2.0.1/bin/cmake/linux/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/CLionProjects/Monopoly_CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Monopoly_Tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Monopoly_Tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Monopoly_Tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Monopoly_Tests.dir/flags.make

CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Board_Tests.cpp
CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Board_Tests.cpp

CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Board_Tests.cpp > CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.i

CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Board_Tests.cpp -o CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.s

CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Dice_Tests.cpp
CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Dice_Tests.cpp

CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Dice_Tests.cpp > CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.i

CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Dice_Tests.cpp -o CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.s

CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Player_Tests.cpp
CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Player_Tests.cpp

CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Player_Tests.cpp > CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.i

CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Player_Tests.cpp -o CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.s

CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/RailRoad_Tests.cpp
CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/RailRoad_Tests.cpp

CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/RailRoad_Tests.cpp > CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.i

CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/RailRoad_Tests.cpp -o CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.s

CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Street_Tests.cpp
CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Street_Tests.cpp

CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Street_Tests.cpp > CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.i

CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Street_Tests.cpp -o CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.s

CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Token_Tests.cpp
CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Token_Tests.cpp

CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Token_Tests.cpp > CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.i

CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Token_Tests.cpp -o CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.s

CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Utility_Tests.cpp
CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Utility_Tests.cpp

CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Utility_Tests.cpp > CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.i

CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Tests/Utility_Tests.cpp -o CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.s

CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp
CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp

CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp > CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.i

CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp -o CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.s

CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp
CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp

CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp > CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.i

CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp -o CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.s

CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp
CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp

CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp > CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.i

CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp -o CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.s

CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o: CMakeFiles/Monopoly_Tests.dir/flags.make
CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp
CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o: CMakeFiles/Monopoly_Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o -MF CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o.d -o CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp

CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp > CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.i

CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp -o CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.s

# Object files for target Monopoly_Tests
Monopoly_Tests_OBJECTS = \
"CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o" \
"CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o"

# External object files for target Monopoly_Tests
Monopoly_Tests_EXTERNAL_OBJECTS =

Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Tests/Board_Tests.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Tests/Dice_Tests.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Tests/Player_Tests.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Tests/RailRoad_Tests.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Tests/Street_Tests.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Tests/Token_Tests.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Tests/Utility_Tests.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Player/Player.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/Player/Token.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/SpecialSquare/CommunityChestCard.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/SpecialSquare/ChanceCard.cpp.o
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/build.make
Monopoly_Tests: /usr/lib/aarch64-linux-gnu/libsfml-graphics.so.2.5.1
Monopoly_Tests: /usr/lib/aarch64-linux-gnu/libsfml-window.so.2.5.1
Monopoly_Tests: /usr/lib/aarch64-linux-gnu/libsfml-system.so.2.5.1
Monopoly_Tests: /usr/lib/aarch64-linux-gnu/libX11.so
Monopoly_Tests: CMakeFiles/Monopoly_Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Monopoly_Tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Monopoly_Tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Monopoly_Tests.dir/build: Monopoly_Tests
.PHONY : CMakeFiles/Monopoly_Tests.dir/build

CMakeFiles/Monopoly_Tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Monopoly_Tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Monopoly_Tests.dir/clean

CMakeFiles/Monopoly_Tests.dir/depend:
	cd /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/Monopoly_CPP /home/ubuntu/CLionProjects/Monopoly_CPP /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles/Monopoly_Tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Monopoly_Tests.dir/depend

