cmake_minimum_required(VERSION 3.0)
project(DS2022_LAB05_STU)
add_subdirectory(googletest)
include_directories(include)
include_directories(googletest/include)
set(CMAKE_CXX_STANDARD 17)

aux_source_directory(src SRC_DIR)
aux_source_directory(tests TESTS_DIR)

message(STATUS ${SRC_DIR})
message(STATUS ${TESTS_DIR})

add_library(DS2022_LAB05_STU STATIC ${SRC_DIR})
add_executable(DS2022_LAB05_STU_TEST ${TESTS_DIR})
target_link_libraries(DS2022_LAB05_STU_TEST DS2022_LAB05_STU gtest gtest_main)



