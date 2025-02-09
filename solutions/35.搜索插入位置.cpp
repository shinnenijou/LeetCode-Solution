/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right) >> 1;
            if(target == nums[mid]) break;
            else if(target < nums[mid]) {
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return (left + right) >> 1;
    }
};
// @lc code=end

