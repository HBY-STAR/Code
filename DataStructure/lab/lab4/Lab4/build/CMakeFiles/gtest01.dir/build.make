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
CMAKE_SOURCE_DIR = C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build

# Include any dependencies generated for this target.
include CMakeFiles/gtest01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gtest01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest01.dir/flags.make

CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj: CMakeFiles/gtest01.dir/flags.make
CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj: CMakeFiles/gtest01.dir/includes_CXX.rsp
CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj: ../tests/BinaryTreeTest.cpp
CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj: CMakeFiles/gtest01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj -MF CMakeFiles\gtest01.dir\tests\BinaryTreeTest.cpp.obj.d -o CMakeFiles\gtest01.dir\tests\BinaryTreeTest.cpp.obj -c C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\tests\BinaryTreeTest.cpp

CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\tests\BinaryTreeTest.cpp > CMakeFiles\gtest01.dir\tests\BinaryTreeTest.cpp.i

CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\tests\BinaryTreeTest.cpp -o CMakeFiles\gtest01.dir\tests\BinaryTreeTest.cpp.s

CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj: CMakeFiles/gtest01.dir/flags.make
CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj: CMakeFiles/gtest01.dir/includes_CXX.rsp
CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj: ../src/BinaryNode.cpp
CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj: CMakeFiles/gtest01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj -MF CMakeFiles\gtest01.dir\src\BinaryNode.cpp.obj.d -o CMakeFiles\gtest01.dir\src\BinaryNode.cpp.obj -c C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\src\BinaryNode.cpp

CMakeFiles/gtest01.dir/src/BinaryNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest01.dir/src/BinaryNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\src\BinaryNode.cpp > CMakeFiles\gtest01.dir\src\BinaryNode.cpp.i

CMakeFiles/gtest01.dir/src/BinaryNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest01.dir/src/BinaryNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\src\BinaryNode.cpp -o CMakeFiles\gtest01.dir\src\BinaryNode.cpp.s

CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj: CMakeFiles/gtest01.dir/flags.make
CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj: CMakeFiles/gtest01.dir/includes_CXX.rsp
CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj: ../src/BinaryTree.cpp
CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj: CMakeFiles/gtest01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj -MF CMakeFiles\gtest01.dir\src\BinaryTree.cpp.obj.d -o CMakeFiles\gtest01.dir\src\BinaryTree.cpp.obj -c C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\src\BinaryTree.cpp

CMakeFiles/gtest01.dir/src/BinaryTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest01.dir/src/BinaryTree.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\src\BinaryTree.cpp > CMakeFiles\gtest01.dir\src\BinaryTree.cpp.i

CMakeFiles/gtest01.dir/src/BinaryTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest01.dir/src/BinaryTree.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\src\BinaryTree.cpp -o CMakeFiles\gtest01.dir\src\BinaryTree.cpp.s

# Object files for target gtest01
gtest01_OBJECTS = \
"CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj" \
"CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj" \
"CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj"

# External object files for target gtest01
gtest01_EXTERNAL_OBJECTS =

gtest01.exe: CMakeFiles/gtest01.dir/tests/BinaryTreeTest.cpp.obj
gtest01.exe: CMakeFiles/gtest01.dir/src/BinaryNode.cpp.obj
gtest01.exe: CMakeFiles/gtest01.dir/src/BinaryTree.cpp.obj
gtest01.exe: CMakeFiles/gtest01.dir/build.make
gtest01.exe: lib/libgtest.a
gtest01.exe: lib/libgtest_main.a
gtest01.exe: lib/libgtest.a
gtest01.exe: CMakeFiles/gtest01.dir/linklibs.rsp
gtest01.exe: CMakeFiles/gtest01.dir/objects1.rsp
gtest01.exe: CMakeFiles/gtest01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable gtest01.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest01.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest01.dir/build: gtest01.exe
.PHONY : CMakeFiles/gtest01.dir/build

CMakeFiles/gtest01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\gtest01.dir\cmake_clean.cmake
.PHONY : CMakeFiles/gtest01.dir/clean

CMakeFiles/gtest01.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4 C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4 C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build C:\Users\21714\Desktop\Code\DataStructure\lab\lab4\Lab4\build\CMakeFiles\gtest01.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest01.dir/depend

