#include "catch_amalgamated.hpp"
#include "catch_amalgamated.cpp"

#include "sort.h"

TEST_CASE("build-test") {
    using solution = PlainMergeSort::Solution;

    vector<int> input;
    vector<int> expect;

    input = {5, 2, 3, 1};
    expect = {1, 2, 3, 5};
    REQUIRE(solution::sortArray(input) == expect);

    input = {5, 1, 1, 2, 0, 0};
    expect = {0, 0, 1, 1, 2, 5};
    REQUIRE(solution::sortArray(input) == expect);
}