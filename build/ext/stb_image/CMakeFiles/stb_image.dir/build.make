# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build

# Include any dependencies generated for this target.
include ext/stb_image/CMakeFiles/stb_image.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ext/stb_image/CMakeFiles/stb_image.dir/compiler_depend.make

# Include the progress variables for this target.
include ext/stb_image/CMakeFiles/stb_image.dir/progress.make

# Include the compile flags for this target's objects.
include ext/stb_image/CMakeFiles/stb_image.dir/flags.make

ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.o: ext/stb_image/CMakeFiles/stb_image.dir/flags.make
ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.o: /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/ext/stb_image/src/stb_image.c
ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.o: ext/stb_image/CMakeFiles/stb_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.o"
	cd /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/ext/stb_image && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.o -MF CMakeFiles/stb_image.dir/src/stb_image.c.o.d -o CMakeFiles/stb_image.dir/src/stb_image.c.o -c /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/ext/stb_image/src/stb_image.c

ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stb_image.dir/src/stb_image.c.i"
	cd /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/ext/stb_image && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/ext/stb_image/src/stb_image.c > CMakeFiles/stb_image.dir/src/stb_image.c.i

ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stb_image.dir/src/stb_image.c.s"
	cd /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/ext/stb_image && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/ext/stb_image/src/stb_image.c -o CMakeFiles/stb_image.dir/src/stb_image.c.s

# Object files for target stb_image
stb_image_OBJECTS = \
"CMakeFiles/stb_image.dir/src/stb_image.c.o"

# External object files for target stb_image
stb_image_EXTERNAL_OBJECTS =

ext/stb_image/libstb_image.so: ext/stb_image/CMakeFiles/stb_image.dir/src/stb_image.c.o
ext/stb_image/libstb_image.so: ext/stb_image/CMakeFiles/stb_image.dir/build.make
ext/stb_image/libstb_image.so: ext/stb_image/CMakeFiles/stb_image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libstb_image.so"
	cd /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/ext/stb_image && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stb_image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/stb_image/CMakeFiles/stb_image.dir/build: ext/stb_image/libstb_image.so
.PHONY : ext/stb_image/CMakeFiles/stb_image.dir/build

ext/stb_image/CMakeFiles/stb_image.dir/clean:
	cd /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/ext/stb_image && $(CMAKE_COMMAND) -P CMakeFiles/stb_image.dir/cmake_clean.cmake
.PHONY : ext/stb_image/CMakeFiles/stb_image.dir/clean

ext/stb_image/CMakeFiles/stb_image.dir/depend:
	cd /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/ext/stb_image /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/ext/stb_image /media/sh3xe/hdd_win/documents/dev/projets/editeur_3d/build/ext/stb_image/CMakeFiles/stb_image.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/stb_image/CMakeFiles/stb_image.dir/depend
