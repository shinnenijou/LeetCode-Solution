//
// Created by YuxinLiu on 2024/01/15.
//

#include <algorithm>
#include <unordered_map>
#include <stack>

#include "problems.h"

ListNode *createList(const std::vector<int> &values) {
    ListNode *head = nullptr;

    for (auto iter = values.rbegin(); iter != values.rend(); ++iter) {
        auto curr = new ListNode(*iter, head);
        head = curr;
    }

    return head;
}

void deleteList(ListNode *head) {
    while (head) {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

std::vector<int> createVector(ListNode *head) {
    std::vector<int> ret;

    while (head) {
        ret.push_back(head->val);
        head = head->next;
    }

    return ret;
}

ListNode *AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    auto *head = new ListNode;
    ListNode *curr = head;

    while (l1 && l2) {
        int value = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        auto *temp = new ListNode(value);
        curr->next = temp;
        curr = temp;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        int value = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        auto *temp = new ListNode(value);
        curr->next = temp;
        curr = temp;
        l1 = l1->next;
    }

    while (l2) {
        int value = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        auto *temp = new ListNode(value);
        curr->next = temp;
        curr = temp;
        l2 = l2->next;
    }

    if (carry){
        curr->next = new ListNode(carry);
    }

    ListNode *ret = head->next;
    delete head;
    return ret;
}

ListNode *ReverseLinkedList::_reverseListRecursive(ListNode *head) {
    if (!head->next){
        newHead = head;
    }
    else{
        ListNode *prev = _reverseListRecursive(head->next);
        prev->next = head;
    }

    head->next = nullptr;
    return head;
}

ListNode *ReverseLinkedList::reverseListRecursive(ListNode *head) {
    if (!head) return nullptr;
    _reverseListRecursive(head);
    return newHead;
}

ListNode *ReverseLinkedList::reverseListIterative(ListNode *head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

std::vector<int> TwoSum::twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i) {
        int need_num = target - nums[i];

        auto iter = map.find(nums[i]);

        if (iter != map.end()) {
            return {iter->second, i};
        }

        map[need_num] = i;
    }

    return {};
}

int LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstringLinear(const std::string &s) {
    int length = 0;
    int max = 0;

    for (int i = 0; i < s.size(); ++i) {
        int repeatIndex = i - length;
        for (; repeatIndex < i && s[repeatIndex] != s[i]; ++repeatIndex);
        length = i == repeatIndex ? length + 1 : i - repeatIndex;
        max = length > max ? length : max;
    }

    return max;
}

int LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstringMap(const std::string &s) {
    const int NIL = -1;
    int map[256];

    for (int &i: map) {
        i = NIL;
    }

    int length = 0;
    int max = 0;

    for (int i = 0; i < s.size(); ++i) {
        length = map[s[i]] >= i - length && map[s[i]] < i ? i - map[s[i]] : length + 1;
        max = length > max ? length : max;
        map[s[i]] = i;
    }

    return max;
}

bool ValidParentheses::isValid(const std::string &s) {
    std::stack<char> stack;

    for (char c: s) {
        switch (c) {
            case '{':
            case '[':
            case '(':
                stack.push(c);
                break;
            case '}':
                if (stack.empty() || stack.top() != '{') return false;
                stack.pop();
                break;
            case ']':
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
                break;
            case ')':
                if (stack.empty() || stack.top() != '(') return false;
                stack.pop();
                break;
            default:
                break;
        }
    }

    return stack.empty();
}

int RemoveDuplicatesFromSortedArray::removeDuplicates(std::vector<int> &nums) {
    int i = 0;  // point to last unique element
    int j = 1;  // point to current processing element

    for (; j < nums.size(); ++j) {
        i += (nums[j] != nums[i]);
        nums[i] = nums[j];
    }

    return i + 1;
}

int RemoveElement::removeElement(std::vector<int> &nums, int val) {
    int last = (int)nums.size() - 1;  // point to the last element to be keep
    int i = 0;  // point to the current processing element

    // 当前元素不需要和last交换, 直接用last覆盖即可
    while (i <= last){
        int temp = nums[i];
        nums[i] = temp == val ? nums[last] : nums[i];
        last -= (temp == val);
        i += (temp != val);
    }

    return last + 1;
}

int MaximumSubarray::maxSubArrayDC(vector<int> &nums, int left, int right) {
    if (right == left){
        return nums[left];
    }

    int mid = left + ((right - left) >> 1 );

    int leftMaxSubarray = maxSubArrayDC(nums, left, mid);
    int rightMaxSubarray = maxSubArrayDC(nums, mid + 1, right);
    int crossingMaxSubarray = maxCrossingSubArrayDC(nums, left, mid, right);

    int max = leftMaxSubarray;
    max = rightMaxSubarray > max ? rightMaxSubarray : max;
    max = crossingMaxSubarray > max ? crossingMaxSubarray : max;

    return max;
}

int MaximumSubarray::maxCrossingSubArrayDC(vector<int> &nums, int left, int mid, int right) {
    int leftSum = 0;
    int leftMax = INT_MIN;
    int rightSum = 0;
    int rightMax = INT_MIN;

    for (int i = mid; i >= left; --i){
        leftSum += nums[i];
        leftMax = leftSum > leftMax ? leftSum : leftMax;
    }

    for (int i = mid + 1; i <= right; ++i){
        rightSum += nums[i];
        rightMax = rightSum > rightMax ? rightSum : rightMax;
    }

    return leftMax + rightMax;
}

int MaximumSubarray::maxSubArrayDC(vector<int> &nums) {
    return maxSubArrayDC(nums, 0, (int)nums.size() - 1);
}

int MaximumSubarray::maxSubArrayDP(vector<int> &nums) {
    int maxSum = nums[0];
    int prevSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        prevSum = nums[i] + (prevSum < 0 ? 0 : prevSum);
        maxSum = prevSum > maxSum ? prevSum : maxSum;
    }

    return maxSum;
}


