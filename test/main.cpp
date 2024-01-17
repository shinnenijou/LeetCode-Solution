#include "catch_amalgamated.hpp"

#include "sort.h"
#include "list.h"
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

TEST_CASE("TwoSum") {
    using solution = TwoSum;

    std::vector<int> nums;
    int target;
    std::vector<int> expect;

    nums = {2, 7, 11, 15};
    target = 9;
    expect = {0, 1};
    REQUIRE(solution::twoSum(nums, target) == expect);

    nums = {3, 2, 4};
    target = 6;
    expect = {1, 2};
    REQUIRE(solution::twoSum(nums, target) == expect);

    nums = {3, 3};
    target = 6;
    expect = {0, 1};
    REQUIRE(solution::twoSum(nums, target) == expect);
}

TEST_CASE("LongestSubstringWithoutRepeatingCharacters") {
    using solution = LongestSubstringWithoutRepeatingCharacters;

    std::string input;
    int expect;

    input = "";
    expect = 0;
    REQUIRE(solution::lengthOfLongestSubstringLinear(input) == expect);
    REQUIRE(solution::lengthOfLongestSubstringMap(input) == expect);

    input = "abcabcbb";
    expect = 3;
    REQUIRE(solution::lengthOfLongestSubstringLinear(input) == expect);
    REQUIRE(solution::lengthOfLongestSubstringMap(input) == expect);

    input = "bbbbb";
    expect = 1;
    REQUIRE(solution::lengthOfLongestSubstringLinear(input) == expect);
    REQUIRE(solution::lengthOfLongestSubstringMap(input) == expect);

    input = "pwwkew";
    expect = 3;
    REQUIRE(solution::lengthOfLongestSubstringLinear(input) == expect);
    REQUIRE(solution::lengthOfLongestSubstringMap(input) == expect);
}

TEST_CASE("AddTwoNumbers") {
    using solution = AddTwoNumbers;

    std::vector<int> input;
    std::vector<int> expect;
    ListNode *L1;
    ListNode *L2;
    ListNode *output;

    L1 = createList({2, 4, 3});
    L2 = createList({5, 6, 4});
    expect = {7, 0, 8};
    output = solution::addTwoNumbers(L1, L2);
    REQUIRE(createVector(output) == expect);
    deleteList(L1);
    deleteList(L2);
    deleteList(output);

    L1 = createList({0});
    L2 = createList({0});
    expect = {0};
    output = solution::addTwoNumbers(L1, L2);
    REQUIRE(createVector(output) == expect);
    deleteList(L1);
    deleteList(L2);
    deleteList(output);

    L1 = createList({9, 9, 9, 9, 9, 9, 9});
    L2 = createList({9, 9, 9, 9});
    expect = {8, 9, 9, 9, 0, 0, 0, 1};
    output = solution::addTwoNumbers(L1, L2);
    REQUIRE(createVector(output) == expect);
    deleteList(L1);
    deleteList(L2);
    deleteList(output);
}

TEST_CASE("ReverseLinkedList") {
    auto solution = ReverseLinkedList();

    std::vector<int> expect;
    ListNode *head;
    ListNode *output;

    head = createList({});
    expect = {};
    output = solution.reverseListRecursive(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList({1, 2, 3, 4, 5});
    expect = {5, 4, 3, 2, 1};
    output = solution.reverseListRecursive(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList({1, 2});
    expect = {2, 1};
    output = solution.reverseListRecursive(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList({});
    expect = {};
    output = solution.reverseListIterative(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList({1, 2, 3, 4, 5});
    expect = {5, 4, 3, 2, 1};
    output = solution.reverseListIterative(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList({1, 2});
    expect = {2, 1};
    output = solution.reverseListIterative(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);
}

TEST_CASE("ValidParentheses"){
    using solution = ValidParentheses;

    REQUIRE(solution::isValid("()") == true);
    REQUIRE(solution::isValid("()[]{}") == true);
    REQUIRE(solution::isValid("(]") == false);
    REQUIRE(solution::isValid("]") == false);
}

TEST_CASE("RemoveDuplicatesFromSortedArray"){
    using solution = RemoveDuplicatesFromSortedArray;

    std::vector<int> input;
    int expect;

    input = {1,1,2};
    expect = 2;
    REQUIRE(solution::removeDuplicates(input) == expect);

    input = {0,0,1,1,1,2,2,3,3,4};
    expect = 5;
    REQUIRE(solution::removeDuplicates(input) == expect);

    input = {0};
    expect = 1;
    REQUIRE(solution::removeDuplicates(input) == expect);
}