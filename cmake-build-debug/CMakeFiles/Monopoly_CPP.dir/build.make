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
include CMakeFiles/Monopoly_CPP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Monopoly_CPP.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Monopoly_CPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Monopoly_CPP.dir/flags.make

CMakeFiles/Monopoly_CPP.dir/main.cpp.o: CMakeFiles/Monopoly_CPP.dir/flags.make
CMakeFiles/Monopoly_CPP.dir/main.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/main.cpp
CMakeFiles/Monopoly_CPP.dir/main.cpp.o: CMakeFiles/Monopoly_CPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Monopoly_CPP.dir/main.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_CPP.dir/main.cpp.o -MF CMakeFiles/Monopoly_CPP.dir/main.cpp.o.d -o CMakeFiles/Monopoly_CPP.dir/main.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/main.cpp

CMakeFiles/Monopoly_CPP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_CPP.dir/main.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/main.cpp > CMakeFiles/Monopoly_CPP.dir/main.cpp.i

CMakeFiles/Monopoly_CPP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_CPP.dir/main.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/main.cpp -o CMakeFiles/Monopoly_CPP.dir/main.cpp.s

CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o: CMakeFiles/Monopoly_CPP.dir/flags.make
CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp
CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o: CMakeFiles/Monopoly_CPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o -MF CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o.d -o CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp

CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp > CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.i

CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Player.cpp -o CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.s

CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o: CMakeFiles/Monopoly_CPP.dir/flags.make
CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp
CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o: CMakeFiles/Monopoly_CPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o -MF CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o.d -o CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp

CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp > CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.i

CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/Player/Token.cpp -o CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.s

CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o: CMakeFiles/Monopoly_CPP.dir/flags.make
CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp
CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o: CMakeFiles/Monopoly_CPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o -MF CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o.d -o CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp

CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp > CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.i

CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/CommunityChestCard.cpp -o CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.s

CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o: CMakeFiles/Monopoly_CPP.dir/flags.make
CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o: /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp
CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o: CMakeFiles/Monopoly_CPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o -MF CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o.d -o CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o -c /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp

CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp > CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.i

CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/CLionProjects/Monopoly_CPP/SpecialSquare/ChanceCard.cpp -o CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.s

# Object files for target Monopoly_CPP
Monopoly_CPP_OBJECTS = \
"CMakeFiles/Monopoly_CPP.dir/main.cpp.o" \
"CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o" \
"CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o" \
"CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o" \
"CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o"

# External object files for target Monopoly_CPP
Monopoly_CPP_EXTERNAL_OBJECTS =

Monopoly_CPP: CMakeFiles/Monopoly_CPP.dir/main.cpp.o
Monopoly_CPP: CMakeFiles/Monopoly_CPP.dir/Player/Player.cpp.o
Monopoly_CPP: CMakeFiles/Monopoly_CPP.dir/Player/Token.cpp.o
Monopoly_CPP: CMakeFiles/Monopoly_CPP.dir/SpecialSquare/CommunityChestCard.cpp.o
Monopoly_CPP: CMakeFiles/Monopoly_CPP.dir/SpecialSquare/ChanceCard.cpp.o
Monopoly_CPP: CMakeFiles/Monopoly_CPP.dir/build.make
Monopoly_CPP: CMakeFiles/Monopoly_CPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Monopoly_CPP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Monopoly_CPP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Monopoly_CPP.dir/build: Monopoly_CPP
.PHONY : CMakeFiles/Monopoly_CPP.dir/build

CMakeFiles/Monopoly_CPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Monopoly_CPP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Monopoly_CPP.dir/clean

CMakeFiles/Monopoly_CPP.dir/depend:
	cd /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/Monopoly_CPP /home/ubuntu/CLionProjects/Monopoly_CPP /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug /home/ubuntu/CLionProjects/Monopoly_CPP/cmake-build-debug/CMakeFiles/Monopoly_CPP.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Monopoly_CPP.dir/depend

