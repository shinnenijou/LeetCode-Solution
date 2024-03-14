//
// Created by YuxinLiu on 2024/01/15.
//

#include <algorithm>
#include <unordered_map>

#include "problems.h"


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


