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

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/li/git_linux_lean/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/li/git_linux_lean/project/build

# Include any dependencies generated for this target.
include CMakeFiles/SrvExample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SrvExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SrvExample.dir/flags.make

CMakeFiles/SrvExample.dir/src/SrvExample.c.o: CMakeFiles/SrvExample.dir/flags.make
CMakeFiles/SrvExample.dir/src/SrvExample.c.o: ../src/SrvExample.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/li/git_linux_lean/project/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/SrvExample.dir/src/SrvExample.c.o"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/SrvExample.dir/src/SrvExample.c.o   -c /home/li/git_linux_lean/project/src/SrvExample.c

CMakeFiles/SrvExample.dir/src/SrvExample.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SrvExample.dir/src/SrvExample.c.i"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/li/git_linux_lean/project/src/SrvExample.c > CMakeFiles/SrvExample.dir/src/SrvExample.c.i

CMakeFiles/SrvExample.dir/src/SrvExample.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SrvExample.dir/src/SrvExample.c.s"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/li/git_linux_lean/project/src/SrvExample.c -o CMakeFiles/SrvExample.dir/src/SrvExample.c.s

CMakeFiles/SrvExample.dir/src/SrvExample.c.o.requires:
.PHONY : CMakeFiles/SrvExample.dir/src/SrvExample.c.o.requires

CMakeFiles/SrvExample.dir/src/SrvExample.c.o.provides: CMakeFiles/SrvExample.dir/src/SrvExample.c.o.requires
	$(MAKE) -f CMakeFiles/SrvExample.dir/build.make CMakeFiles/SrvExample.dir/src/SrvExample.c.o.provides.build
.PHONY : CMakeFiles/SrvExample.dir/src/SrvExample.c.o.provides

CMakeFiles/SrvExample.dir/src/SrvExample.c.o.provides.build: CMakeFiles/SrvExample.dir/src/SrvExample.c.o

# Object files for target SrvExample
SrvExample_OBJECTS = \
"CMakeFiles/SrvExample.dir/src/SrvExample.c.o"

# External object files for target SrvExample
SrvExample_EXTERNAL_OBJECTS =

SrvExample: CMakeFiles/SrvExample.dir/src/SrvExample.c.o
SrvExample: CMakeFiles/SrvExample.dir/build.make
SrvExample: libGDBusServer.a
SrvExample: CMakeFiles/SrvExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable SrvExample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SrvExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SrvExample.dir/build: SrvExample
.PHONY : CMakeFiles/SrvExample.dir/build

CMakeFiles/SrvExample.dir/requires: CMakeFiles/SrvExample.dir/src/SrvExample.c.o.requires
.PHONY : CMakeFiles/SrvExample.dir/requires

CMakeFiles/SrvExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SrvExample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SrvExample.dir/clean

CMakeFiles/SrvExample.dir/depend:
	cd /home/li/git_linux_lean/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/li/git_linux_lean/project /home/li/git_linux_lean/project /home/li/git_linux_lean/project/build /home/li/git_linux_lean/project/build /home/li/git_linux_lean/project/build/CMakeFiles/SrvExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SrvExample.dir/depend
