/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<string>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        int reverted_x = 0;
        while(x > reverted_x){
            reverted_x *= 10;
            reverted_x += (x % 10);
            x /= 10;
        }
        return x == reverted_x || x == reverted_x / 10;
    }
};
// @lc code=end

