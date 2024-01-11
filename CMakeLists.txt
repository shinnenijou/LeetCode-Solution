cmake_minimum_required(VERSION 3.27)
project(LeetCode_Solution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(includes)

# Source
add_executable(unit_test
        test/main.cpp
        test/catch_amalgamated.cpp
        src/in-place_merge_sort.cpp
        src/plain_merge_sort.cpp
)