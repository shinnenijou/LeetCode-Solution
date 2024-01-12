#include "catch_amalgamated.hpp"

#include "sort.h"

std::vector<std::vector<int>> SORT_TEST_CASE({
                                                     {5, 2, 3, 1},
                                                     {5, 1, 1, 2, 0, 0},
                                             });

TEST_CASE("PlainMergeSort") {
    using solution = PlainMergeSort;

    auto test_cases = sortTestCase(SORT_TEST_CASE);
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}

TEST_CASE("InplaceMergeSort") {
    using solution = InPlaceMergeSort;

    auto test_cases = sortTestCase(SORT_TEST_CASE);
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}