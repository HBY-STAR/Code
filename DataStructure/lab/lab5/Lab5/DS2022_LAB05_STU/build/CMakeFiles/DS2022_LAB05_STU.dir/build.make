# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Microsoft Visual Studio\IDE   2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Microsoft Visual Studio\IDE   2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\build

# Include any dependencies generated for this target.
include CMakeFiles/DS2022_LAB05_STU.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DS2022_LAB05_STU.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DS2022_LAB05_STU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DS2022_LAB05_STU.dir/flags.make

CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj: CMakeFiles/DS2022_LAB05_STU.dir/flags.make
CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj: CMakeFiles/DS2022_LAB05_STU.dir/includes_CXX.rsp
CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj: ../src/UGraph.cpp
CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj: CMakeFiles/DS2022_LAB05_STU.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj -MF CMakeFiles\DS2022_LAB05_STU.dir\src\UGraph.cpp.obj.d -o CMakeFiles\DS2022_LAB05_STU.dir\src\UGraph.cpp.obj -c C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\src\UGraph.cpp

CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\src\UGraph.cpp > CMakeFiles\DS2022_LAB05_STU.dir\src\UGraph.cpp.i

CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\src\UGraph.cpp -o CMakeFiles\DS2022_LAB05_STU.dir\src\UGraph.cpp.s

# Object files for target DS2022_LAB05_STU
DS2022_LAB05_STU_OBJECTS = \
"CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj"

# External object files for target DS2022_LAB05_STU
DS2022_LAB05_STU_EXTERNAL_OBJECTS =

libDS2022_LAB05_STU.a: CMakeFiles/DS2022_LAB05_STU.dir/src/UGraph.cpp.obj
libDS2022_LAB05_STU.a: CMakeFiles/DS2022_LAB05_STU.dir/build.make
libDS2022_LAB05_STU.a: CMakeFiles/DS2022_LAB05_STU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDS2022_LAB05_STU.a"
	$(CMAKE_COMMAND) -P CMakeFiles\DS2022_LAB05_STU.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DS2022_LAB05_STU.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DS2022_LAB05_STU.dir/build: libDS2022_LAB05_STU.a
.PHONY : CMakeFiles/DS2022_LAB05_STU.dir/build

CMakeFiles/DS2022_LAB05_STU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DS2022_LAB05_STU.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DS2022_LAB05_STU.dir/clean

CMakeFiles/DS2022_LAB05_STU.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\build C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\build C:\Users\21714\Desktop\Code\DataStructure\lab\lab5\Lab5\DS2022_LAB05_STU\build\CMakeFiles\DS2022_LAB05_STU.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DS2022_LAB05_STU.dir/depend

