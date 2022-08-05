/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int sum = ((1 + n) * n ) >> 1;
        for(int i = 0; i != n; i++){
            sum -= nums[i];
        }
        return sum;
    }
};
// @lc code=end

