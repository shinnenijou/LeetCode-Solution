#include "catch_amalgamated.hpp"

#include "sort.h"
#include "problems.h"

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

TEST_CASE("TwoSum"){
    using solution = TwoSum;

    std::vector<int> nums;
    int target = 0;
    std::vector<int> expect;

    nums = {2,7,11,15};
    target = 9;
    expect = {0, 1};
    REQUIRE(solution::twoSum(nums, target) == expect);

    nums = {3,2,4};
    target = 6;
    expect = {1, 2};
    REQUIRE(solution::twoSum(nums, target) == expect);

    nums = {3, 3};
    target = 6;
    expect = {0, 1};
    REQUIRE(solution::twoSum(nums, target) == expect);
}

TEST_CASE("LongestSubstringWithoutRepeatingCharacters"){
    using solution = LongestSubstringWithoutRepeatingCharacters;

    std::string input;
    int expect = 0;

    input = "";
    expect = 0;
    REQUIRE(solution::lengthOfLongestSubstring(input) == expect);

    input = "abcabcbb";
    expect = 3;
    REQUIRE(solution::lengthOfLongestSubstring(input) == expect);

    input = "bbbbb";
    expect = 1;
    REQUIRE(solution::lengthOfLongestSubstring(input) == expect);

    input = "pwwkew";
    expect = 3;
    REQUIRE(solution::lengthOfLongestSubstring(input) == expect);
}