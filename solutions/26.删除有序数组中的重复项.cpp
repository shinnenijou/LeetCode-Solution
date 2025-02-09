/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include<vector>
#include<climits>
using std::vector;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int i = 0;
        for(int j = 0; nums[j] != INT_MAX; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        nums.pop_back();
        return i + 1;
    }
};
// @lc code=end

