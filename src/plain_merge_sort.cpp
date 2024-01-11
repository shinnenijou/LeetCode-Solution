/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 * Plain Merge Sort
 * 合并有序数组时使用辅助缓存, 
 */

// @lc code=start
#include "sort.h"

namespace PlainMergeSort{
    void Solution::_mergeArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t mid, size_t right)
    {
        if (left >= mid || mid >= right)
        {
            return;
        }

        size_t i = left;
        size_t j = mid;
        size_t k = left;

        while (i < mid && j < right)
        {
            if (nums[i] <= nums[j])
            {
                buffer[k++] = nums[i++];
            }
            else
            {
                buffer[k++] = nums[j++];
            }
        }

        while (i < mid)
        {
            buffer[k++] = nums[i++];
        }

        while (j < right)
        {
            buffer[k++] = nums[j++];
        }

        for (size_t index = left; index < k; ++index)
        {
            nums[index] = buffer[index];
        }
    }

    void Solution::_sortArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t right)
    {
        if (right - left <= 1)
        {
            return;
        }

        size_t mid = left + ((right - left) >> 1);

        _sortArray(nums, buffer, left, mid);
        _sortArray(nums, buffer, mid, right);
        _mergeArray(nums, buffer, left, mid, right);
    }

    vector<int> Solution::sortArray(vector<int> &nums)
    {
        vector<int> buffer(nums.size());
        _sortArray(nums, buffer, 0, nums.size());
        return nums;
    }

}
// @lc code=end
