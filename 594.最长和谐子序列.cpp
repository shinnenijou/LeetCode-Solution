/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <vector>
#include <cmath>
#include <map>
// @lc code=start
class Solution
{
public:
    int findLHS(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        std::map<int, int> num_count;
        int max = 0;
        for (int i = 0; i != nums.size(); i++)
        {
            num_count[nums[i]]++;
        }
        std::map<int, int>::iterator iter_2 = num_count.begin(), iter_1 = iter_2++;
        while (iter_2 != num_count.end())
        {
            if (iter_2->first - iter_1->first == 1 && iter_1->second + iter_2->second > max)
            {
                max = iter_1->second + iter_2->second;
            }
            iter_1++, iter_2++;
        }

        return max;
    }
};
// @lc code=end
