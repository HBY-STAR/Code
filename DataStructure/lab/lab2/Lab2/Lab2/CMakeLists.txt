cmake_minimum_required(VERSION 3.19)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

# 增加一个子目录准备使用gtest自带的cmakelists.txt去编译gtest
add_subdirectory(lib/googletest-release-1.12.1)
# 指定gtest的头文件目录
include_directories(lib/googletest-release-1.12.1/googletest/include)
# 指定gmock的头文件目录
include_directories(lib/googletest-release-1.12.1/googlemock/include)
# 指定自己源代码中的头文件目录
include_directories(src)
# 指定自己的源代码所在的目录，并把所有的源代码文件名用GTEST_SRC变量代替
aux_source_directory(src GTEST_SRC)
# 指定生成gtest01(可执行程序的名字)的工程(即gtest01.exe)所需要的源文件
add_executable(gtest01 tests/MyStackTest.cpp tests/MyQueueTest.cpp tests/PostfixTest.cpp ${GTEST_SRC})
# 指定将gtest gtest_main两个链接库，链接到gtest01工程中
target_link_libraries(gtest01 gtest gtest_main)
