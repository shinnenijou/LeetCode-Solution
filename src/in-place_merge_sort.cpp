/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 * In-place Merge Sort
 * 不使用辅助空间的归并排序
 */

// @lc code=start
#include <sort.h>

namespace InPlaceMergeSort {
    void Solution::_mergeArray(vector<int> &nums, int left, int quarter, int mid, int right) {
        int i = left;   // point to left sorted part
        int j = mid;    // point to right sorted part
        int k = quarter; // point to unsorted part
        while (i < quarter && j < right) {
            if (nums[i] <= nums[j]) {
                int temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
                i++, k++;
            } else {
                int temp = nums[k];
                nums[k] = nums[j];
                nums[j] = temp;
                j++, k++;
            }
        }

        while (i < quarter) {
            int temp = nums[k];
            nums[k] = nums[i];
            nums[i] = temp;
            i++, k++;
        }
    }

    // left ~ mid: unsorted, mid ~ right: sorted
    void Solution::_sortArray(vector<int> &nums, int left, int right) {
        if (right - left <= 1) {
            return;
        }

        int mid = left + ((right - left) >> 1);
        _sortArray(nums, mid, right);

        // Note: left~quarter: sorted, quarter~mid: unsorted, mid~right: sorted
        // 注意mid - quarter必须大于quarter - left以完全容纳左半的sorted部分
        int quarter = left + ((mid - left) >> 1);
        _sortArray(nums, left, quarter);

        // 合并已排序的两个部分
        _mergeArray(nums, left, quarter, mid, right);

        // 合并后原本quarter ~ mid未排序的部分会移动到前端, 再对这部分进行排序
        _sortArray(nums, left, left + mid - quarter);
    }

    vector<int> Solution::sortArray(vector<int> &nums) {
        _sortArray(nums, 0, nums.size());
        return nums;
    }

// @lc code=end
}