/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string &s) {
        int length = 0, i = s.size() - 1;
        for(;i >= 0 && s[i] == ' '; i--) ;
        length = i + 1;
        for(; i >= 0 && s[i] != ' '; i--);
        length = length - i - 1;
        return length;
    }
};
// @lc code=end

