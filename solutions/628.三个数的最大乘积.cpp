/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
#include<vector>
#include<algorithm>
using std::vector;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int max_product = nums[0] * nums[1] * nums[2];
        int product_2 = nums[0] * nums[n - 1] * nums[n - 2];
        if (product_2 > max_product) max_product = product_2;
        return max_product;
    }
};
// @lc code=end

