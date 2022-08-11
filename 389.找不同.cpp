/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */
#include<vector>
#include<string>
// @lc code=start
class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        char ret = 0;
        for(int i = 0; i != s.size(); i++){
            ret ^= s[i];
        }
        for(int i = 0; i != t.size(); i++){
            ret ^= t[i];
        }
        return ret;
    }
};
// @lc code=end

