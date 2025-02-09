/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index_map;
        int i = 0, j = 0;
        for(; i != nums.size(); i++){
            auto iter = num_to_index_map.find(target - nums[i]);
            if(iter != num_to_index_map.end() && i != iter->second){
                j = iter->second;
                break;
            }
            num_to_index_map[nums[i]] = i;
        }
        return vector<int>({i, j});
    }
};
// @lc code=end

