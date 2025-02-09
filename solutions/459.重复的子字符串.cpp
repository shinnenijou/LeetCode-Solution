/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include<string>
#include<cmath>
// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(std::string &s) {
        for(int i = 1; i != (s.size() >> 1) + 1; i++){
            int j = 0;
            for(; j != s.size(); j++){
                if(s[j] != s[j % i]) break;
            }
            if(s.size() % i == 0 && j == s.size()) return true;
        }
        return false;
    }
};
// @lc code=end

