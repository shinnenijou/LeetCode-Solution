/*
 * 剑指 Offer 03. 数组中重复的数字
 */

// @lc code=start
#include<vector>
using std::vector;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int dup = -1;
        int ret = -1;
        int i = 0;
        while (i < nums.size())
        {
            if (dup == -1 && nums[i] == i)
            {
                i++;
                continue;
            }

            if (nums[i] == dup)
            {
                ret = dup;
                break;
            }

            int temp = dup;
            dup = nums[i];
            nums[i] = temp;
            i = dup == -1 ? i + 1 : dup;
        }

        return ret;
    }
};
// @lc code=end

