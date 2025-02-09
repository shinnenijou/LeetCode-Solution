/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include<string>
#include<vector>
// @lc code=start
class Solution {
public:
    int longestPalindrome(std::string &s) {
        std::vector char_map('z' - 'A' + 1, 0);
        for(int i = 0; i != s.size(); i++){
            char_map[s[i] - 'A']++;
        }
        int sum = 0;
        for(int i = 0; i != char_map.size(); i++){
            sum += char_map[i] >> 1;
        }
        sum <<= 1;
        if(sum < s.size()){
            sum++;
        }
        return sum;
    }
};
// @lc code=end

