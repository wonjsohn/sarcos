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
CMAKE_BINARY_DIR = /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno

# Include any dependencies generated for this target.
include CMakeFiles/xopengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xopengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xopengl.dir/flags.make

CMakeFiles/xopengl.dir/initUserGraphics.c.o: CMakeFiles/xopengl.dir/flags.make
CMakeFiles/xopengl.dir/initUserGraphics.c.o: /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserGraphics.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/xopengl.dir/initUserGraphics.c.o"
	gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xopengl.dir/initUserGraphics.c.o   -c /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserGraphics.c

CMakeFiles/xopengl.dir/initUserGraphics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xopengl.dir/initUserGraphics.c.i"
	gcc  $(C_DEFINES) $(C_FLAGS) -E /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserGraphics.c > CMakeFiles/xopengl.dir/initUserGraphics.c.i

CMakeFiles/xopengl.dir/initUserGraphics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xopengl.dir/initUserGraphics.c.s"
	gcc  $(C_DEFINES) $(C_FLAGS) -S /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src/initUserGraphics.c -o CMakeFiles/xopengl.dir/initUserGraphics.c.s

CMakeFiles/xopengl.dir/initUserGraphics.c.o.requires:
.PHONY : CMakeFiles/xopengl.dir/initUserGraphics.c.o.requires

CMakeFiles/xopengl.dir/initUserGraphics.c.o.provides: CMakeFiles/xopengl.dir/initUserGraphics.c.o.requires
	$(MAKE) -f CMakeFiles/xopengl.dir/build.make CMakeFiles/xopengl.dir/initUserGraphics.c.o.provides.build
.PHONY : CMakeFiles/xopengl.dir/initUserGraphics.c.o.provides

CMakeFiles/xopengl.dir/initUserGraphics.c.o.provides.build: CMakeFiles/xopengl.dir/initUserGraphics.c.o

# Object files for target xopengl
xopengl_OBJECTS = \
"CMakeFiles/xopengl.dir/initUserGraphics.c.o"

# External object files for target xopengl
xopengl_EXTERNAL_OBJECTS =

xopengl: CMakeFiles/xopengl.dir/initUserGraphics.c.o
xopengl: CMakeFiles/xopengl.dir/build.make
xopengl: CMakeFiles/xopengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable xopengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xopengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xopengl.dir/build: xopengl
.PHONY : CMakeFiles/xopengl.dir/build

CMakeFiles/xopengl.dir/requires: CMakeFiles/xopengl.dir/initUserGraphics.c.o.requires
.PHONY : CMakeFiles/xopengl.dir/requires

CMakeFiles/xopengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xopengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xopengl.dir/clean

CMakeFiles/xopengl.dir/depend:
	cd /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/src /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno /Network/Servers/duerer/Volumes/duerer/guest/prog/masterUser/x86_64xeno/CMakeFiles/xopengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xopengl.dir/depend

