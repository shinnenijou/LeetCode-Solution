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

void InPlaceMergeSort::_mergeArray(std::vector<int> &nums, size_t leftBegin, size_t leftEnd, size_t rightBegin, size_t rightEnd) {
    size_t i = leftBegin;   // point to left sorted part
    size_t j = rightBegin;    // point to right sorted part
    size_t k = rightEnd - (rightEnd - rightBegin + leftEnd - leftBegin); // point to unsorted part(buffer)
    while (i < leftEnd && j < rightEnd) {
        if (nums[i] <= nums[j]) {
            std::swap(nums[k], nums[i]);
            i++, k++;
        } else {
            std::swap(nums[k], nums[j]);
            j++, k++;
        }
    }

    while (i < leftEnd) {
        std::swap(nums[k], nums[i]);
        i++, k++;
    }
}

// left ~ mid: unsorted, mid ~ right: sorted
void InPlaceMergeSort::_sortArray(std::vector<int> &nums, size_t unsortedBegin, size_t sortedBegin, size_t sortedEnd) {
    size_t unsortedEnd = sortedBegin;

    // base case使用冒泡
    if (unsortedEnd - unsortedBegin <= 1){
        size_t  i = unsortedBegin;

        while (i + 1 < sortedEnd && nums[i] > nums[i + 1]){
            std::swap(nums[i], nums[i + 1]);
            i++;
        }

        return;
    }


    // unsortedMid ~ unsortedEnd的部分留作交换的buffer, 必须保证buffer空间比排序的部分大
    // 即: unsortedEnd - unsortedMid >= unsortedMid - unsortedBegin
    // 整型的平均值正好可以满足此要求
    size_t unsortedMid = unsortedBegin + ((unsortedEnd - unsortedBegin) >> 1);
    _sortArray(nums, unsortedBegin, unsortedMid, unsortedMid);

    // 合并已排序的两个部分
    _mergeArray(nums, unsortedBegin, unsortedMid, sortedBegin, sortedEnd);

    // 合并后原本unsortedMid ~ sortedEnd未排序的部分会移动到前端, 再对这部分进行排序
    _sortArray(nums, unsortedBegin, unsortedBegin + unsortedEnd - unsortedMid, sortedEnd);
}

std::vector<int> InPlaceMergeSort::sortArray(std::vector<int> &nums) {
    _sortArray(nums, 0, nums.size(), nums.size());
    return nums;
}

