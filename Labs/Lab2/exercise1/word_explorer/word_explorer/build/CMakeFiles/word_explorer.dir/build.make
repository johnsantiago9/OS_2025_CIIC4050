# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build

# Include any dependencies generated for this target.
include CMakeFiles/word_explorer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/word_explorer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/word_explorer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/word_explorer.dir/flags.make

CMakeFiles/word_explorer.dir/codegen:
.PHONY : CMakeFiles/word_explorer.dir/codegen

CMakeFiles/word_explorer.dir/src/main.c.o: CMakeFiles/word_explorer.dir/flags.make
CMakeFiles/word_explorer.dir/src/main.c.o: /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/main.c
CMakeFiles/word_explorer.dir/src/main.c.o: CMakeFiles/word_explorer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/word_explorer.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/word_explorer.dir/src/main.c.o -MF CMakeFiles/word_explorer.dir/src/main.c.o.d -o CMakeFiles/word_explorer.dir/src/main.c.o -c /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/main.c

CMakeFiles/word_explorer.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/word_explorer.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/main.c > CMakeFiles/word_explorer.dir/src/main.c.i

CMakeFiles/word_explorer.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/word_explorer.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/main.c -o CMakeFiles/word_explorer.dir/src/main.c.s

CMakeFiles/word_explorer.dir/src/functions.c.o: CMakeFiles/word_explorer.dir/flags.make
CMakeFiles/word_explorer.dir/src/functions.c.o: /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/functions.c
CMakeFiles/word_explorer.dir/src/functions.c.o: CMakeFiles/word_explorer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/word_explorer.dir/src/functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/word_explorer.dir/src/functions.c.o -MF CMakeFiles/word_explorer.dir/src/functions.c.o.d -o CMakeFiles/word_explorer.dir/src/functions.c.o -c /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/functions.c

CMakeFiles/word_explorer.dir/src/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/word_explorer.dir/src/functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/functions.c > CMakeFiles/word_explorer.dir/src/functions.c.i

CMakeFiles/word_explorer.dir/src/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/word_explorer.dir/src/functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/src/functions.c -o CMakeFiles/word_explorer.dir/src/functions.c.s

# Object files for target word_explorer
word_explorer_OBJECTS = \
"CMakeFiles/word_explorer.dir/src/main.c.o" \
"CMakeFiles/word_explorer.dir/src/functions.c.o"

# External object files for target word_explorer
word_explorer_EXTERNAL_OBJECTS =

word_explorer: CMakeFiles/word_explorer.dir/src/main.c.o
word_explorer: CMakeFiles/word_explorer.dir/src/functions.c.o
word_explorer: CMakeFiles/word_explorer.dir/build.make
word_explorer: CMakeFiles/word_explorer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable word_explorer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/word_explorer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/word_explorer.dir/build: word_explorer
.PHONY : CMakeFiles/word_explorer.dir/build

CMakeFiles/word_explorer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/word_explorer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/word_explorer.dir/clean

CMakeFiles/word_explorer.dir/depend:
	cd /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise1/word_explorer/word_explorer/build/CMakeFiles/word_explorer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/word_explorer.dir/depend

