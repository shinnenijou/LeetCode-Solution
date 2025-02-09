/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */
#include<string>
// @lc code=start
class Solution {
public:
    bool detectCapitalUse(std::string &word) {
        int isAllCapital = isupper(word.back());

        if(isAllCapital > 0 && isupper(word.front()) == 0){
            return false;
        }

        for(int i = 1; i < word.size() - 1; i++){
            if(isupper(word[i]) != isAllCapital){
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

