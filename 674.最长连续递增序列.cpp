/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include<vector>
using std::vector;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int prev_length = 1;
        int max = 1;
        for(int i = 1; i != nums.size(); i++){
            int length;
            if(nums[i] > nums[i - 1]) length = prev_length + 1;
            else length = 1;
            max = length > max ? length : max;
            prev_length = length;
        }
        return max;
    }
};
// @lc code=end

