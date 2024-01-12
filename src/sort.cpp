#include <algorithm>

#include "sort.h"

std::vector<std::pair<std::vector<int>,std::vector<int>>> sortTestCase(const std::vector<std::vector<int>>& cases){
    std::vector<std::pair<std::vector<int>,std::vector<int>>> ret;

    for (std::vector<int> vec: cases ) {
        std::vector<int> temp(vec.begin(), vec.end());
        std::sort(temp.begin(), temp.end());
        ret.emplace_back(vec, temp);
    }

    return ret;
}

void
PlainMergeSort::_mergeArray(std::vector<int> &nums, std::vector<int> &buffer, size_t left, size_t mid, size_t right) {
    if (left >= mid || mid >= right) {
        return;
    }

    size_t i = left;  // point to assign
    size_t j = mid;  // point to right part
    size_t k = left; // point to left part(aux buffer)

    for (size_t index = left; index < mid; ++index) {
        buffer[index] = nums[index];
    }

    while (k < mid && j < right) {
        nums[i++] = buffer[k] < nums[j] ? buffer[k++] : nums[j++];
    }

    while (k < mid) {
        nums[i++] = buffer[k++];
    }
}

void PlainMergeSort::_sortArray(std::vector<int> &nums, std::vector<int> &buffer, size_t left, size_t right) {
    if (right - left <= 1) {
        return;
    }

    size_t mid = left + ((right - left) >> 1);

    _sortArray(nums, buffer, left, mid);
    _sortArray(nums, buffer, mid, right);
    _mergeArray(nums, buffer, left, mid, right);
}

std::vector<int> PlainMergeSort::sortArray(std::vector<int> &nums) {
    std::vector<int> buffer(nums.size());
    _sortArray(nums, buffer, 0, nums.size());
    return nums;
}

void InPlaceMergeSort::_mergeArray(std::vector<int> &nums, size_t left, size_t quarter, size_t mid, size_t right) {
    size_t i = left;   // point to left sorted part
    size_t j = mid;    // point to right sorted part
    size_t k = quarter; // point to unsorted part
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
void InPlaceMergeSort::_sortArray(std::vector<int> &nums, size_t left, size_t right) {
    if (right - left <= 1) {
        return;
    }

    size_t mid = left + ((right - left) >> 1);
    _sortArray(nums, mid, right);

    // Note: left~quarter: sorted, quarter~mid: unsorted, mid~right: sorted
    // 注意mid - quarter必须大于quarter - left以完全容纳左半的sorted部分
    size_t quarter = left + ((mid - left) >> 1);
    _sortArray(nums, left, quarter);

    // 合并已排序的两个部分
    _mergeArray(nums, left, quarter, mid, right);

    // 合并后原本quarter ~ mid未排序的部分会移动到前端, 再对这部分进行排序
    _sortArray(nums, left, left + mid - quarter);
}

std::vector<int> InPlaceMergeSort::sortArray(std::vector<int> &nums) {
    _sortArray(nums, 0, nums.size());
    return nums;
}

