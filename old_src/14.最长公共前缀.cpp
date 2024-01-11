/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include<vector>
#include<string>
using std::vector; using std::string;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs.front();
        int longest_prefix_length = strs.front().size();
        for(int i = 1; i != strs.size(); i++){
            if(strs[i].empty()) return string("");
            int j = 0;
            for(; j != longest_prefix_length && j != strs[i].size(); j++){
                if(strs[i][j] !=  strs.front()[j]) break;
            }
            longest_prefix_length = j;
        }
        return string(strs.front().begin(), strs.front().begin() + longest_prefix_length);
    }
};
// @lc code=end

