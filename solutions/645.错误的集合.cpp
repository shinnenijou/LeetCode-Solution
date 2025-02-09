/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
#include<algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int k = 1, duplicate = 0, lost = 0;
        for(int i = 0; i != nums.size(); i++){
            if(nums[i] - i > k){
                lost = nums[i] - 1;
                k++;
            }
            else if(nums[i] - i < k){
                duplicate = nums[i];
                k--;
            }
        }
        if(lost == 0) lost = nums.back() + 1;
        return std::vector<int>({duplicate, lost});
    }
};
// @lc code=end

