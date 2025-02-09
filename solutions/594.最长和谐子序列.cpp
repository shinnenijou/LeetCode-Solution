/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <vector>
#include <cmath>
#include <unordered_map>
// @lc code=start
class Solution
{
public:
    int findLHS(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        std::unordered_map<int, int> num_count;
        int max = 0;
        for (int i = 0; i != nums.size(); i++)
        {
            num_count[nums[i]]++;
        }
        for(auto iter = num_count.begin(); iter != num_count.end(); iter++)
        {   
            auto temp_iter = num_count.find(iter->first + 1);
            if(temp_iter != num_count.end()){
                int temp = temp_iter->second + iter->second;
                max = temp > max ? temp : max;
            }
        }

        return max;
    }
};
// @lc code=end
