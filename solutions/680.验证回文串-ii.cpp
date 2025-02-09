/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string &s) {
        int i = 0, j = s.size() - 1;
        bool delete_flag = false;
        bool delete_left, delete_right;
        while(i < j){
            if(s[i] != s[j] && !delete_flag){
                delete_flag = true;
                if(s[j - 1] == s[i]){
                    j--;
                }
                else{
                    return false;
                }
            }
            i++, j--;
        }

        return true;
    }
};
// @lc code=end

