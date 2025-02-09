cmake_minimum_required(VERSION 3.27)
project(LeetCode_Solution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(includes)
aux_source_directory(solutions SRC_LIST)

# Source
add_executable(unit_test
        ${SRC_LIST}
        test/catch_amalgamated.cpp
)