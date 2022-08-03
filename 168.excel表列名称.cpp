/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
#include<string>
// @lc code=start
class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string ret;
        while(columnNumber > 0){
            ret.push_back('A' + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1 ) / 26;
        }
        for(int i = 0, j = ret.size() - 1; i < j; i++, j--){
            char temp = ret[i];
            ret[i] = ret[j];
            ret[j] = temp;
        }
        return ret;
    }
};
// @lc code=end

