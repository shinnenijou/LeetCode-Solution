#include "catch_amalgamated.hpp"

#include "sort.h"

TEST_CASE("PlainMergeSort") {
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

TEST_CASE("InplaceMergeSort") {
    using solution = InPlaceMergeSort::Solution;

    vector<int> input;
    vector<int> expect;

    input = {5, 2, 3, 1};
    expect = {1, 2, 3, 5};
    REQUIRE(solution::sortArray(input) == expect);

    input = {5, 1, 1, 2, 0, 0};
    expect = {0, 0, 1, 1, 2, 5};
    REQUIRE(solution::sortArray(input) == expect);
}