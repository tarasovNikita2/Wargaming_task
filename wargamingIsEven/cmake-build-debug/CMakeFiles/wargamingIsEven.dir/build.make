# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/163/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/163/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tarasov2/CLionProjects/wargamingIsEven

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tarasov2/CLionProjects/wargamingIsEven/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wargamingIsEven.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/wargamingIsEven.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wargamingIsEven.dir/flags.make

CMakeFiles/wargamingIsEven.dir/main.cpp.o: CMakeFiles/wargamingIsEven.dir/flags.make
CMakeFiles/wargamingIsEven.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tarasov2/CLionProjects/wargamingIsEven/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wargamingIsEven.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wargamingIsEven.dir/main.cpp.o -c /home/tarasov2/CLionProjects/wargamingIsEven/main.cpp

CMakeFiles/wargamingIsEven.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wargamingIsEven.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tarasov2/CLionProjects/wargamingIsEven/main.cpp > CMakeFiles/wargamingIsEven.dir/main.cpp.i

CMakeFiles/wargamingIsEven.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wargamingIsEven.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tarasov2/CLionProjects/wargamingIsEven/main.cpp -o CMakeFiles/wargamingIsEven.dir/main.cpp.s

# Object files for target wargamingIsEven
wargamingIsEven_OBJECTS = \
"CMakeFiles/wargamingIsEven.dir/main.cpp.o"

# External object files for target wargamingIsEven
wargamingIsEven_EXTERNAL_OBJECTS =

wargamingIsEven: CMakeFiles/wargamingIsEven.dir/main.cpp.o
wargamingIsEven: CMakeFiles/wargamingIsEven.dir/build.make
wargamingIsEven: CMakeFiles/wargamingIsEven.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tarasov2/CLionProjects/wargamingIsEven/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wargamingIsEven"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wargamingIsEven.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wargamingIsEven.dir/build: wargamingIsEven
.PHONY : CMakeFiles/wargamingIsEven.dir/build

CMakeFiles/wargamingIsEven.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wargamingIsEven.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wargamingIsEven.dir/clean

CMakeFiles/wargamingIsEven.dir/depend:
	cd /home/tarasov2/CLionProjects/wargamingIsEven/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tarasov2/CLionProjects/wargamingIsEven /home/tarasov2/CLionProjects/wargamingIsEven /home/tarasov2/CLionProjects/wargamingIsEven/cmake-build-debug /home/tarasov2/CLionProjects/wargamingIsEven/cmake-build-debug /home/tarasov2/CLionProjects/wargamingIsEven/cmake-build-debug/CMakeFiles/wargamingIsEven.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wargamingIsEven.dir/depend
