# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /home/frodo/public/ugls_lab-2.53.0/packages/cmake-3.11.2/bin/cmake

# The command to remove a file.
RM = /home/frodo/public/ugls_lab-2.53.0/packages/cmake-3.11.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tania05/SENG475/basics-tania05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tania05/SENG475/basics-tania05/builds

# Include any dependencies generated for this target.
include CMakeFiles/test_rational.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_rational.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_rational.dir/flags.make

CMakeFiles/test_rational.dir/app/test_rational.cpp.o: CMakeFiles/test_rational.dir/flags.make
CMakeFiles/test_rational.dir/app/test_rational.cpp.o: ../app/test_rational.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tania05/SENG475/basics-tania05/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_rational.dir/app/test_rational.cpp.o"
	/home/frodo/public/ugls_lab-2.53.0/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_rational.dir/app/test_rational.cpp.o -c /home/tania05/SENG475/basics-tania05/app/test_rational.cpp

CMakeFiles/test_rational.dir/app/test_rational.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_rational.dir/app/test_rational.cpp.i"
	/home/frodo/public/ugls_lab-2.53.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tania05/SENG475/basics-tania05/app/test_rational.cpp > CMakeFiles/test_rational.dir/app/test_rational.cpp.i

CMakeFiles/test_rational.dir/app/test_rational.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_rational.dir/app/test_rational.cpp.s"
	/home/frodo/public/ugls_lab-2.53.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tania05/SENG475/basics-tania05/app/test_rational.cpp -o CMakeFiles/test_rational.dir/app/test_rational.cpp.s

# Object files for target test_rational
test_rational_OBJECTS = \
"CMakeFiles/test_rational.dir/app/test_rational.cpp.o"

# External object files for target test_rational
test_rational_EXTERNAL_OBJECTS =

test_rational: CMakeFiles/test_rational.dir/app/test_rational.cpp.o
test_rational: CMakeFiles/test_rational.dir/build.make
test_rational: CMakeFiles/test_rational.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tania05/SENG475/basics-tania05/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_rational"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_rational.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_rational.dir/build: test_rational

.PHONY : CMakeFiles/test_rational.dir/build

CMakeFiles/test_rational.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_rational.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_rational.dir/clean

CMakeFiles/test_rational.dir/depend:
	cd /home/tania05/SENG475/basics-tania05/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tania05/SENG475/basics-tania05 /home/tania05/SENG475/basics-tania05 /home/tania05/SENG475/basics-tania05/builds /home/tania05/SENG475/basics-tania05/builds /home/tania05/SENG475/basics-tania05/builds/CMakeFiles/test_rational.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_rational.dir/depend
