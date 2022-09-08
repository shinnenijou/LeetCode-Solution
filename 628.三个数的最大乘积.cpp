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
        vector<int> &inner_nums = nums;
        int max_product = 1;
        int n = nums.size();
        std::sort(inner_nums.begin(), inner_nums.end(), std::greater<int>());
        int product_1 = inner_nums[0] * inner_nums[1] * inner_nums[2];
        int product_2 = inner_nums[0] * inner_nums[n - 1] * inner_nums[n - 2];
        max_product = product_1 > product_2 ? product_1 : product_2;
        return max_product;
    }
};
// @lc code=end

