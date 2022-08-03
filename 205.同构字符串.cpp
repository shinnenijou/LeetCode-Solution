/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include<string>
#include<unordered_map>
// @lc code=start
class Solution {
public:
    bool isIsomorphic(std::string &s, std::string &t) {
        if(s.size() != t.size()){
            return false;
        }

        if (s.empty()){
            return true;
        }


    }
};
// @lc code=end

