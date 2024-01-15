//
// Created by YuxinLiu on 2024/01/15.
//

#ifndef LEETCODE_SOLUTION_PROBLEMS_H
#define LEETCODE_SOLUTION_PROBLEMS_H

#include <vector>
#include <string>

class TwoSum{
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target);
};

class LongestSubstringWithoutRepeatingCharacters{
public:
    static int lengthOfLongestSubstringLinear(const std::string& s);
    static int lengthOfLongestSubstringMap(const std::string& s);
};


#endif //LEETCODE_SOLUTION_PROBLEMS_H
