#include <algorithm>
#include <random>
#include <functional>

#include "sort.h"

std::vector<std::pair<std::vector<int>, std::vector<int>>> sortTestCase() {
    const int MAX_LENGTH = 100;
    const int MAX_VALUE = 10;

    std::vector<std::pair<std::vector<int>, std::vector<int>>> ret;
    std::vector<std::vector<int>> cases;

    // random sequences
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, MAX_VALUE);

    for (int i = 0; i < MAX_LENGTH; ++i) {
        std::vector<int> temp;

        temp.reserve(i);

        for (int j = 0; j < i; ++j) {
            temp.push_back(distrib(gen));
        }

        cases.push_back(temp);
    }

    // A list with all zeros
    for (int i = 0; i < MAX_LENGTH; ++i) {
        std::vector<int> temp;
        temp.reserve(i);

        for (int j = 0; j < i; ++j) {
            temp.push_back(0);
        }

        cases.push_back(temp);
    }

    // An ordered list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        std::vector<int> temp;
        temp.reserve(i);

        for (int j = 0; j < i; ++j) {
            temp.push_back(distrib(gen));
        }

        std::sort(temp.begin(), temp.end());
        cases.push_back(temp);
    }

    // A reversed list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        std::vector<int> temp;
        temp.reserve(i);

        for (int j = 0; j < i; ++j) {
            temp.push_back(distrib(gen));
        }

        std::sort(temp.begin(), temp.end(), std::greater<>());
        cases.push_back(temp);
    }

    for (std::vector<int> vec: cases) {
        std::vector<int> temp(vec.begin(), vec.end());
        std::sort(temp.begin(), temp.end());
        ret.emplace_back(vec, temp);
    }

    return ret;
}

void
PlainMergeSort::mergeArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t mid, size_t right) {
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

void PlainMergeSort::sortArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t right) {
    if (right - left <= 1) {
        return;
    }

    size_t mid = left + ((right - left) >> 1);

    sortArray(nums, buffer, left, mid);
    sortArray(nums, buffer, mid, right);
    mergeArray(nums, buffer, left, mid, right);
}

std::vector<int> PlainMergeSort::sortArray(std::vector<int> &nums) {
    std::vector<int> buffer(nums.size());
    sortArray(nums, buffer, 0, nums.size());
    return nums;
}

void InPlaceMergeSort::mergeArray(vector<int> &nums, size_t leftBegin, size_t leftEnd, size_t rightBegin,
                                  size_t rightEnd) {
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

void InPlaceMergeSort::sortArray(vector<int> &nums, size_t unsortedBegin, size_t sortedBegin, size_t sortedEnd) {
    size_t unsortedEnd = sortedBegin;

    // base case使用冒泡
    if (unsortedEnd - unsortedBegin <= 1) {
        size_t i = unsortedBegin;

        while (i + 1 < sortedEnd && nums[i] > nums[i + 1]) {
            std::swap(nums[i], nums[i + 1]);
            i++;
        }

        return;
    }


    // unsortedMid ~ unsortedEnd的部分留作交换的buffer, 必须保证buffer空间比排序的部分大
    // 即: unsortedEnd - unsortedMid >= unsortedMid - unsortedBegin
    // 整型的平均值正好可以满足此要求
    size_t unsortedMid = unsortedBegin + ((unsortedEnd - unsortedBegin) >> 1);
    sortArray(nums, unsortedBegin, unsortedMid, unsortedMid);

    // 合并已排序的两个部分
    mergeArray(nums, unsortedBegin, unsortedMid, sortedBegin, sortedEnd);

    // 合并后原本unsortedMid ~ sortedEnd未排序的部分会移动到前端, 再对这部分进行排序
    sortArray(nums, unsortedBegin, unsortedBegin + unsortedEnd - unsortedMid, sortedEnd);
}

std::vector<int> InPlaceMergeSort::sortArray(std::vector<int> &nums) {
    sortArray(nums, 0, nums.size(), nums.size());
    return nums;
}


void HeapSort::buildMaxHeap(vector<int> &nums) {
    for (int i = (((int) nums.size()) - 1) >> 1; i >= 0; --i) {
        maxHeapify(nums, i);
    }
}

vector<int> HeapSort::sortArray(vector<int> &nums) {
    heapSize = (int) nums.size();
    buildMaxHeap(nums);

    for (int i = (int) nums.size() - 1; i >= 0; --i) {
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        heapSize--;
        maxHeapify(nums, 0);
    }

    return nums;
}

void HeapSort::maxHeapify(vector<int> &nums, int i) {
    if (leftChild(i) >= heapSize) {
        return;
    }

    int largest = nums[leftChild(i)] > nums[i] ? leftChild(i) : i;

    if (rightChild(i) < heapSize) {
        largest = nums[rightChild(i)] > nums[largest] ? rightChild(i) : largest;
    }

    if (largest != i) {
        int temp = nums[i];
        nums[i] = nums[largest];
        nums[largest] = temp;
        maxHeapify(nums, largest);
    }
}

vector<int> QuickSort::sortArray(vector<int> &nums) {
    sortArray(nums, 0, (int) nums.size() - 1);
    return nums;
}

int QuickSort::partition(vector<int> &nums, int left, int right) {
    int x = nums[right];

    int j = left - 1;
    for (int i = left; i < right; ++i){
        if (nums[i] < x){
            j++;
            std::swap(nums[i], nums[j]);
        }
    }

    j++;
    std::swap(nums[right], nums[j]);

    return j;
}

void QuickSort::sortArray(vector<int> &nums, int left, int right) {
    if (right <= left){
        return;
    }

    int mid = partition(nums, left, right);
    sortArray(nums, left, mid - 1);
    sortArray(nums, mid + 1, right);
}

vector<int> CountingSort::sortArray(vector<int> &nums) {
    vector<int> count(valueScale, 0);
    vector<int> result(nums.size());

    for (int num : nums){
        count[num]++;
    }

    for (int i = 1; i < count.size(); ++i){
        count[i] = count[i] + count[i - 1];
    }

    for (int i = (int)nums.size() - 1; i >= 0; --i){
        result[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }

    return result;
}
