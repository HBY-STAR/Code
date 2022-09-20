cmake_minimum_required(VERSION 3.0)
project(DS2022_LAB01_TA)
add_subdirectory(googletest)
include_directories(include)
include_directories(googletest/googletest/include)

set(CMAKE_CXX_STANDARD 17)

add_library(DS2022_LAB01_TA STATIC
        src/Node.cpp src/LinkedListVectorConverter.cpp src/Problem1.cpp
        src/PolynomialTerm.cpp src/Problem2.cpp)
add_executable(DS2022_LAB01_TA_TEST
        tests/src/Problem1Test.cpp tests/src/Problem2Test.cpp)
target_link_libraries(DS2022_LAB01_TA_TEST DS2022_LAB01_TA gtest gtest_main)
