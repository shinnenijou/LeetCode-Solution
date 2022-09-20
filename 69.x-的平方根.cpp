/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        float y_1 = x, y_2 = 0.5 + (float)x * 0.5;
        while (y_1 - y_2 > 0.1){
            y_1 = y_2;
            y_2 = ((float)x * 0.5)/y_2 + 0.5 * y_2;
        }
        int ret = (int)y_2;
        if(ret * ret > x) ret--;
        return ret;
    }
};
// @lc code=end

