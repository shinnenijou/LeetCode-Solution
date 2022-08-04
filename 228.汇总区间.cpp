/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include<climits>
#include<string>
#include<vector>
#include<cstdlib>
// @lc code=start
class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> ret;
        
        if (nums.empty()){
            return ret;
        }

        int min = nums[0], max = nums[0], prev = nums[0];
        for(int i = 1; i != nums.size(); i++){
            if(nums[i] == prev + 1){
                max = nums[i];
            }
            else{
                if(min < max){
                    ret.push_back(std::to_string(min) +  "->" + std::to_string(max));
                }
                else{
                    ret.push_back(std::to_string(min));
                }
                min = nums[i];
            }
            prev = nums[i];
        }

        if(min < max){
            ret.push_back(std::to_string(min) +  "->" + std::to_string(max));
        }
        else{
            ret.push_back(std::to_string(min));
        }

        return ret;
    }
};
// @lc code=end

