/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)return false;
        
        bool stop = false;
        while(!stop){
            if((n & 1) == 0){
                n >>= 1;
                continue;
            }
            if(n % 3 == 0){
                n /= 3;
                continue;
            }
            if(n % 5 == 0){
                n /= 5;
                continue;
            }
            stop = true;
        }
        if(n == 1) return true;
        return false;
    }
};
// @lc code=end

