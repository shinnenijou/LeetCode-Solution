/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include<vector>
// @lc code=start
class NumArray {
    std::vector<int> m_sums;
    std::vector<int> m_nums;
public:
    NumArray(std::vector<int>& nums):
        m_sums(nums.size(), 0),
        m_nums(nums.size(), 0)
    {
        if(nums.empty()){
            return;
        }
        m_nums[0] = m_sums[0] = nums[0];
        for(int i = 1; i != nums.size(); i++){
            m_nums[i] = nums[i];
            m_sums[i] = m_sums[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return m_sums[right] - m_sums[left] + m_nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

