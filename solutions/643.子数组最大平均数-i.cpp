/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, i;
        for(i = 0; i != k && i != nums.size(); i++){
            sum += nums[i];
        }
        double max_avarage = sum / i;

        int lood_end = nums.size() - k;
        for(i = 0; i < lood_end; i++){
            sum -= nums[i];
            sum += nums[i + k];
            double average = sum / k;
            max_avarage = average > max_avarage ? average : max_avarage;
        }

        return max_avarage;
    }
};
// @lc code=end

