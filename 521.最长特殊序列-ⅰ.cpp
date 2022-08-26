/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */
#include<string>
// @lc code=start
class Solution {
public:
    int findLUSlength(std::string &a, std::string &b) {
        return a == b?-1:(a.size()>b.size()?a.size():b.size());
    }
};
// @lc code=end

