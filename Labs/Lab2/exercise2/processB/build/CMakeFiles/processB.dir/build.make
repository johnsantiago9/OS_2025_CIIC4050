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
CMAKE_SOURCE_DIR = /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build

# Include any dependencies generated for this target.
include CMakeFiles/processB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/processB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/processB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/processB.dir/flags.make

CMakeFiles/processB.dir/codegen:
.PHONY : CMakeFiles/processB.dir/codegen

CMakeFiles/processB.dir/src/main.c.o: CMakeFiles/processB.dir/flags.make
CMakeFiles/processB.dir/src/main.c.o: /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/main.c
CMakeFiles/processB.dir/src/main.c.o: CMakeFiles/processB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/processB.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/processB.dir/src/main.c.o -MF CMakeFiles/processB.dir/src/main.c.o.d -o CMakeFiles/processB.dir/src/main.c.o -c /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/main.c

CMakeFiles/processB.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/processB.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/main.c > CMakeFiles/processB.dir/src/main.c.i

CMakeFiles/processB.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/processB.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/main.c -o CMakeFiles/processB.dir/src/main.c.s

CMakeFiles/processB.dir/src/functions.c.o: CMakeFiles/processB.dir/flags.make
CMakeFiles/processB.dir/src/functions.c.o: /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/functions.c
CMakeFiles/processB.dir/src/functions.c.o: CMakeFiles/processB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/processB.dir/src/functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/processB.dir/src/functions.c.o -MF CMakeFiles/processB.dir/src/functions.c.o.d -o CMakeFiles/processB.dir/src/functions.c.o -c /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/functions.c

CMakeFiles/processB.dir/src/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/processB.dir/src/functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/functions.c > CMakeFiles/processB.dir/src/functions.c.i

CMakeFiles/processB.dir/src/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/processB.dir/src/functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/src/functions.c -o CMakeFiles/processB.dir/src/functions.c.s

# Object files for target processB
processB_OBJECTS = \
"CMakeFiles/processB.dir/src/main.c.o" \
"CMakeFiles/processB.dir/src/functions.c.o"

# External object files for target processB
processB_EXTERNAL_OBJECTS =

processB: CMakeFiles/processB.dir/src/main.c.o
processB: CMakeFiles/processB.dir/src/functions.c.o
processB: CMakeFiles/processB.dir/build.make
processB: CMakeFiles/processB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable processB"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/processB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/processB.dir/build: processB
.PHONY : CMakeFiles/processB.dir/build

CMakeFiles/processB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/processB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/processB.dir/clean

CMakeFiles/processB.dir/depend:
	cd /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build /Users/johnsantiago/OS_2025_CIIC4050/Lab1/Lab2/exercise2/processB/build/CMakeFiles/processB.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/processB.dir/depend

