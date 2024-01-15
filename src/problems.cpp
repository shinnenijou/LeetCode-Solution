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
