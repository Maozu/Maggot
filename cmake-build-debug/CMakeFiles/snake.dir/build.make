# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.5.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.5.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mao-z\Documents\GitHub\Maggot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mao-z\Documents\GitHub\Maggot\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/snake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/snake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snake.dir/flags.make

CMakeFiles/snake.dir/main.c.obj: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mao-z\Documents\GitHub\Maggot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/snake.dir/main.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\snake.dir\main.c.obj   -c C:\Users\mao-z\Documents\GitHub\Maggot\main.c

CMakeFiles/snake.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snake.dir/main.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mao-z\Documents\GitHub\Maggot\main.c > CMakeFiles\snake.dir\main.c.i

CMakeFiles/snake.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snake.dir/main.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mao-z\Documents\GitHub\Maggot\main.c -o CMakeFiles\snake.dir\main.c.s

CMakeFiles/snake.dir/main.c.obj.requires:

.PHONY : CMakeFiles/snake.dir/main.c.obj.requires

CMakeFiles/snake.dir/main.c.obj.provides: CMakeFiles/snake.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\snake.dir\build.make CMakeFiles/snake.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/snake.dir/main.c.obj.provides

CMakeFiles/snake.dir/main.c.obj.provides.build: CMakeFiles/snake.dir/main.c.obj


# Object files for target snake
snake_OBJECTS = \
"CMakeFiles/snake.dir/main.c.obj"

# External object files for target snake
snake_EXTERNAL_OBJECTS =

snake.exe: CMakeFiles/snake.dir/main.c.obj
snake.exe: CMakeFiles/snake.dir/build.make
snake.exe: CMakeFiles/snake.dir/linklibs.rsp
snake.exe: CMakeFiles/snake.dir/objects1.rsp
snake.exe: CMakeFiles/snake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mao-z\Documents\GitHub\Maggot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable snake.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\snake.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snake.dir/build: snake.exe

.PHONY : CMakeFiles/snake.dir/build

CMakeFiles/snake.dir/requires: CMakeFiles/snake.dir/main.c.obj.requires

.PHONY : CMakeFiles/snake.dir/requires

CMakeFiles/snake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\snake.dir\cmake_clean.cmake
.PHONY : CMakeFiles/snake.dir/clean

CMakeFiles/snake.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mao-z\Documents\GitHub\Maggot C:\Users\mao-z\Documents\GitHub\Maggot C:\Users\mao-z\Documents\GitHub\Maggot\cmake-build-debug C:\Users\mao-z\Documents\GitHub\Maggot\cmake-build-debug C:\Users\mao-z\Documents\GitHub\Maggot\cmake-build-debug\CMakeFiles\snake.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snake.dir/depend

