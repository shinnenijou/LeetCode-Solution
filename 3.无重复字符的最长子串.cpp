/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<vector>
using std::vector;
class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        if(s.empty()) return 0;
        vector<int> length_of_LSS(s.size(), 1);
        int max = 1;
        for(int i = 1; i < s.size(); i++){
            int j = i - 1;
            for(; j >= i - length_of_LSS[i - 1]; j--){
                if(s[j] == s[i]){
                    break;
                }
            }
            length_of_LSS[i] = i - j;
            max = length_of_LSS[i] > max ? length_of_LSS[i] : max;
        }
        return max;
    }
};
// @lc code=end

