# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/V00906949A5P1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/V00906949A5P1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/V00906949A5P1.dir/flags.make

CMakeFiles/V00906949A5P1.dir/main.c.o: CMakeFiles/V00906949A5P1.dir/flags.make
CMakeFiles/V00906949A5P1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/V00906949A5P1.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/V00906949A5P1.dir/main.c.o   -c /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/main.c

CMakeFiles/V00906949A5P1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/V00906949A5P1.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/main.c > CMakeFiles/V00906949A5P1.dir/main.c.i

CMakeFiles/V00906949A5P1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/V00906949A5P1.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/main.c -o CMakeFiles/V00906949A5P1.dir/main.c.s

# Object files for target V00906949A5P1
V00906949A5P1_OBJECTS = \
"CMakeFiles/V00906949A5P1.dir/main.c.o"

# External object files for target V00906949A5P1
V00906949A5P1_EXTERNAL_OBJECTS =

V00906949A5P1: CMakeFiles/V00906949A5P1.dir/main.c.o
V00906949A5P1: CMakeFiles/V00906949A5P1.dir/build.make
V00906949A5P1: CMakeFiles/V00906949A5P1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable V00906949A5P1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/V00906949A5P1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/V00906949A5P1.dir/build: V00906949A5P1

.PHONY : CMakeFiles/V00906949A5P1.dir/build

CMakeFiles/V00906949A5P1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/V00906949A5P1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/V00906949A5P1.dir/clean

CMakeFiles/V00906949A5P1.dir/depend:
	cd /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1 /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1 /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/cmake-build-debug /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/cmake-build-debug /Users/ezranestel/Documents/GitHub/csc-projects/V00906949A5P1/cmake-build-debug/CMakeFiles/V00906949A5P1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/V00906949A5P1.dir/depend

