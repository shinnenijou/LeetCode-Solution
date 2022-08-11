/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int cnt = 0;
        while(temp){
            cnt++;
            temp &= (temp - 1);
        }
        return cnt;
    }
};
// @lc code=end

