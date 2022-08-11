/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */
#include<cmath>
// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        double y = n;
        y = (-1 + std::sqrt(1 + 8 * y))/2;
        return (int)y;
    }
};
// @lc code=end

