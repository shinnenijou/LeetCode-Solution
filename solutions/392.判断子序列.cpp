/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include<string>
// @lc code=start
class Solution {
private:
    bool _isSubsequence(std::string s, std::string t, int i, int j){
        if(i == s.size()) return true;

        while(j != t.size() && s[i] != t[j]){
            j++;
        }

        if(j == t.size()) return false;
        return _isSubsequence(s, t, i + 1, j + 1);
    }  
public:
    bool isSubsequence(std::string s, std::string t) {
        return _isSubsequence(s, t, 0, 0);
    }
};
// @lc code=end

