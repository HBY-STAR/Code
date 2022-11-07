cmake_minimum_required(VERSION 3.19)
project(Lab6)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest-release-1.12.1)
include_directories(lib/googletest-release-1.12.1/googletest/include)
include_directories(lib/googletest-release-1.12.1/googlemock/include)
include_directories(src)
aux_source_directory(src GTEST_SRC)
add_executable(gtest01 tests/KruskalTest.cpp ${GTEST_SRC})
target_link_libraries(gtest01 gtest gtest_main)