/*
 * 剑指 Offer 11. 旋转数组的最小数字
 */

// @lc code=start
#include<vector>
using std::vector;

class Solution {
private:
    int _findMin(vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }

        if (nums[left] < nums[right])
        {
            return nums[left];
        }
        else
        {
            int mid = left + (right - left) >> 1;
            if (nums[mid] > nums[left])
            {
                return _findMin(nums, mid + 1, right);
            }
            else if (nums[mid] < nums[left])
            {
                return _findMin(nums, left, mid);
            }
            else
            {
                int min = nums[left];
                for (int i = left; i <= right; ++i)
                {
                    if (nums[i] < min)
                    {
                        min = nums[i];
                    }
                }
                return min;
            }
        }
    }

public:
    int findMin(vector<int>& nums) {
        return _findMin(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

