#include "catch_amalgamated.hpp"

#include "sort.h"
#include "problems.h"
#include "heap.hpp"
#include "list.hpp"

TEST_CASE("InsertSort") {
    using solution = InsertSort;

    auto test_cases = sortTestCase();
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}

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

TEST_CASE("HeapSort") {
    using solution = HeapSort;

    auto test_cases = sortTestCase();
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}

TEST_CASE("QuickSort") {
    using solution = QuickSort;

    auto test_cases = sortTestCase();
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}

TEST_CASE("CountingSort") {
    using solution = CountingSort;

    auto test_cases = sortTestCase();
    for (auto test_case: test_cases) {
        REQUIRE(solution::sortArray(test_case.first) == test_case.second);
    }
}

TEST_CASE("TwoSum") {
    using solution = TwoSum;

    std::vector<int> nums;
    int target = 0;
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
    int expect = 0;

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
    ListNode *L1 = nullptr;
    ListNode *L2 = nullptr;
    ListNode *output = nullptr;

    L1 = createList(input = {2, 4, 3});
    L2 = createList(input = {5, 6, 4});
    expect = {7, 0, 8};
    output = solution::addTwoNumbers(L1, L2);
    REQUIRE(createVector(output) == expect);
    deleteList(L1);
    deleteList(L2);
    deleteList(output);

    L1 = createList(input = {0});
    L2 = createList(input = {0});
    expect = {0};
    output = solution::addTwoNumbers(L1, L2);
    REQUIRE(createVector(output) == expect);
    deleteList(L1);
    deleteList(L2);
    deleteList(output);

    L1 = createList(input = {9, 9, 9, 9, 9, 9, 9});
    L2 = createList(input = {9, 9, 9, 9});
    expect = {8, 9, 9, 9, 0, 0, 0, 1};
    output = solution::addTwoNumbers(L1, L2);
    REQUIRE(createVector(output) == expect);
    deleteList(L1);
    deleteList(L2);
    deleteList(output);
}

TEST_CASE("ReverseLinkedList") {
    auto solution = ReverseLinkedList();

    std::vector<int> input;
    std::vector<int> expect;
    ListNode *head = nullptr;
    ListNode *output = nullptr;

    head = createList(input = {});
    expect = {};
    output = solution.reverseListRecursive(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList(input = {1, 2, 3, 4, 5});
    expect = {5, 4, 3, 2, 1};
    output = solution.reverseListRecursive(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList(input = {1, 2});
    expect = {2, 1};
    output = solution.reverseListRecursive(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList(input = {});
    expect = {};
    output = solution.reverseListIterative(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList(input = {1, 2, 3, 4, 5});
    expect = {5, 4, 3, 2, 1};
    output = solution.reverseListIterative(head);
    REQUIRE(createVector(output) == expect);
    deleteList(output);

    head = createList(input = {1, 2});
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

TEST_CASE("RemoveElement"){
    using solution = RemoveElement;

    std::vector<int> input;
    int value;
    int expect;

    input = {3,2,2,3};
    value = 3;
    expect = 2;
    REQUIRE(solution::removeElement(input, value) == expect);

    input = {0,1,2,2,3,0,4,2};
    value = 2;
    expect = 5;
    REQUIRE(solution::removeElement(input, value) == expect);

    input = {0};
    value = 1;
    expect = 1;
    REQUIRE(solution::removeElement(input, value) == expect);
}

TEST_CASE("MaximumSubarray") {
    using solution = MaximumSubarray;

    std::vector<int> input;

    input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    REQUIRE(solution::maxSubArrayDP(input) == 6);
    REQUIRE(solution::maxSubArrayDC(input) == 6);

    input = {1};
    REQUIRE(solution::maxSubArrayDP(input) == 1);
    REQUIRE(solution::maxSubArrayDC(input) == 1);

    input = {5, 4, -1, 7, 8};
    REQUIRE(solution::maxSubArrayDP(input) == 23);
    REQUIRE(solution::maxSubArrayDC(input) == 23);
}

TEST_CASE("PriorityQueue") {
    PriorityQueue<int, int> pQueue;

    pQueue.push(5, 1);
    pQueue.push(1, 10);
    pQueue.push(10, 100);

    REQUIRE(pQueue.top().second == 100);
    pQueue.pop();
    REQUIRE(pQueue.top().second == 1);
    pQueue.pop();
    REQUIRE(pQueue.top().second == 10);
    pQueue.pop();
}

TEST_CASE("ForwardList") {
    List<int> list;

    list.push_back(1);
    REQUIRE(list.toVector() == vector<int>({1}));

    list.push_back(2);
    REQUIRE(list.toVector() == vector<int>({1, 2}));


    list.push_back(3);
    REQUIRE(list.toVector() == vector<int>({1, 2, 3}));

    list.pop_back();
    REQUIRE(list.toVector() == vector<int>({1, 2}));

    list.pop_back();
    REQUIRE(list.toVector() == vector<int>({1}));

    list.pop_back();
    REQUIRE(list.empty() == true);
}

TEST_CASE("DualList") {
    DualList<int> list;

    list.push_back(1);
    REQUIRE(list.toVector() == vector<int>({1}));

    list.pop_back();
    REQUIRE(list.toVector() == vector<int>({}));

    list.push_front(1);
    REQUIRE(list.toVector() == vector<int>({1}));

    list.pop_front();
    REQUIRE(list.toVector() == vector<int>({}));

    list.push_back(1);
    list.push_front(2);
    REQUIRE(list.toVector() == vector<int>({2, 1}));

    list.pop_front();
    list.pop_front();
    REQUIRE(list.toVector() == vector<int>({}));

    list.push_back(1);
    list.push_front(2);
    REQUIRE(list.toVector() == vector<int>({2, 1}));

    list.pop_back();
    list.pop_back();
    REQUIRE(list.toVector() == vector<int>({}));

    list.push_back(1);
    list.push_front(2);
    list.push_back(3);
    list.push_front(4);
    REQUIRE(list.toVector() == vector<int>({4, 2, 1, 3}));
}