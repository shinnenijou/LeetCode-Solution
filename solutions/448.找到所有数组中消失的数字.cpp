/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include<vector>
// @lc code=start
class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for(int i = 0; i != nums.size(); i++){
            int j = nums[i] - 1;
            while(j != nums[j] - 1){
                int temp = nums[j];
                nums[j] = j + 1;
                j = temp - 1;
            }
        }
        std::vector<int> ret;
        for(int i = 0; i != nums.size(); i++){
            if(i + 1 != nums[i]){
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
// @lc code=end

