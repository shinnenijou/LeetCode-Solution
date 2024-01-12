#include "catch_amalgamated.hpp"

#include "sort.h"

TEST_CASE("PlainMergeSort") {
    using solution = PlainMergeSort;

    auto test_cases = sortTestCase();
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}

TEST_CASE("InplaceMergeSort") {
    using solution = InPlaceMergeSort;

    auto test_cases = sortTestCase();
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}