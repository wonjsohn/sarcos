# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64

# Include any dependencies generated for this target.
include CMakeFiles/xsimulation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xsimulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xsimulation.dir/flags.make

CMakeFiles/xsimulation.dir/initUserSimulation.c.o: CMakeFiles/xsimulation.dir/flags.make
CMakeFiles/xsimulation.dir/initUserSimulation.c.o: /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserSimulation.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/xsimulation.dir/initUserSimulation.c.o"
	gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xsimulation.dir/initUserSimulation.c.o   -c /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserSimulation.c

CMakeFiles/xsimulation.dir/initUserSimulation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xsimulation.dir/initUserSimulation.c.i"
	gcc  $(C_DEFINES) $(C_FLAGS) -E /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserSimulation.c > CMakeFiles/xsimulation.dir/initUserSimulation.c.i

CMakeFiles/xsimulation.dir/initUserSimulation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xsimulation.dir/initUserSimulation.c.s"
	gcc  $(C_DEFINES) $(C_FLAGS) -S /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserSimulation.c -o CMakeFiles/xsimulation.dir/initUserSimulation.c.s

CMakeFiles/xsimulation.dir/initUserSimulation.c.o.requires:
.PHONY : CMakeFiles/xsimulation.dir/initUserSimulation.c.o.requires

CMakeFiles/xsimulation.dir/initUserSimulation.c.o.provides: CMakeFiles/xsimulation.dir/initUserSimulation.c.o.requires
	$(MAKE) -f CMakeFiles/xsimulation.dir/build.make CMakeFiles/xsimulation.dir/initUserSimulation.c.o.provides.build
.PHONY : CMakeFiles/xsimulation.dir/initUserSimulation.c.o.provides

CMakeFiles/xsimulation.dir/initUserSimulation.c.o.provides.build: CMakeFiles/xsimulation.dir/initUserSimulation.c.o

# Object files for target xsimulation
xsimulation_OBJECTS = \
"CMakeFiles/xsimulation.dir/initUserSimulation.c.o"

# External object files for target xsimulation
xsimulation_EXTERNAL_OBJECTS =

xsimulation: CMakeFiles/xsimulation.dir/initUserSimulation.c.o
xsimulation: CMakeFiles/xsimulation.dir/build.make
xsimulation: CMakeFiles/xsimulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable xsimulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xsimulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xsimulation.dir/build: xsimulation
.PHONY : CMakeFiles/xsimulation.dir/build

CMakeFiles/xsimulation.dir/requires: CMakeFiles/xsimulation.dir/initUserSimulation.c.o.requires
.PHONY : CMakeFiles/xsimulation.dir/requires

CMakeFiles/xsimulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xsimulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xsimulation.dir/clean

CMakeFiles/xsimulation.dir/depend:
	cd /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64 /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64 /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64/CMakeFiles/xsimulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xsimulation.dir/depend

