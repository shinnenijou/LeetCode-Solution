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
    /*
     * 动态规划, 记录以每个字符为结尾的最长无重复字串并更新。两个方法的区别在加入新字符串后如何搜索当前最长子串里是否有重复字符
     * Linear使用逆序的线性搜索，不需要额外空间，但最坏时每个字符都需要比较当前字符前的所有字符，最差时时间复杂度为O(n^2)
     * Map使用数组记录每个字符上次出现的索引并和当前字符索引比较, 时间复杂度为O(n)并仅需要常数空间
     * 字符集较大时可以采用其他Map结构实现来减小空间消耗，典型的树形实现下时间为O(nlogn)
     */
    static int lengthOfLongestSubstringLinear(const std::string& s);
    static int lengthOfLongestSubstringMap(const std::string& s);
};


#endif //LEETCODE_SOLUTION_PROBLEMS_H
