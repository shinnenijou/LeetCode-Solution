#include <algorithm>
#include <random>
#include <cmath>

#include "sort.h"

std::vector<std::pair<std::vector<int>, std::vector<int>>> sortTestCase() {
    const int MAX_LENGTH = 100;
    const int MAX_VALUE = 23;
    const int MIN_VALUE = -23;

    std::vector<std::pair<std::vector<int>, std::vector<int>>> ret;
    std::vector<std::vector<int>> cases;

    // random sequences
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(MIN_VALUE, MAX_VALUE);

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

std::vector<int> PlainMergeSort::sortArray(std::vector<int> &nums) {
    vector<int> buffer(nums.size());

    const int SORT_TYPE = 0;
    const int MERGE_TYPE = 1;

    vector<int> stack;
    stack.push_back(0);
    stack.push_back((int)nums.size());
    stack.push_back(SORT_TYPE);

    while(!stack.empty()) {
        int type = stack.back();
        stack.pop_back();

        if (type == SORT_TYPE){
            int right = stack.back();
            stack.pop_back();

            int left = stack.back();
            stack.pop_back();

            if (right - left <= 1) {
                continue;
            }

            int mid = left + ((right - left) >> 1);

            stack.push_back(left);
            stack.push_back(mid);
            stack.push_back(right);
            stack.push_back(MERGE_TYPE);

            stack.push_back(left);
            stack.push_back(mid);
            stack.push_back(SORT_TYPE);

            stack.push_back(mid);
            stack.push_back(right);
            stack.push_back(SORT_TYPE);
        }
        else if (type == MERGE_TYPE){
           int right = stack.back();
           stack.pop_back();

           int mid = stack.back();
           stack.pop_back();

           int left = stack.back();
           stack.pop_back();

           mergeArray(nums, buffer, left, mid, right);
        }

    }

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


void HeapSort::buildMaxHeap(vector<int> &nums, int heapSize) {
    for (int i = (((int) nums.size()) - 1) >> 1; i >= 0; --i) {
        maxHeapify(nums, i, heapSize);
    }
}

vector<int> HeapSort::sortArray(vector<int> &nums) {
    int heapSize = (int) nums.size();
    buildMaxHeap(nums, heapSize);

    for (int i = (int) nums.size() - 1; i >= 0; --i) {
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        heapSize--;
        maxHeapify(nums, 0, heapSize);
    }

    return nums;
}

void HeapSort::maxHeapify(vector<int> &nums, int i, int heapSize) {
    while (leftChild(i) < heapSize) {
        int largest = nums[leftChild(i)] > nums[i] ? leftChild(i) : i;

        if (rightChild(i) < heapSize) {
            largest = nums[rightChild(i)] > nums[largest] ? rightChild(i) : largest;
        }

        if (largest == i) {
            break;
        }

        std::swap(nums[i], nums[largest]);
        i = largest;
    }
}

int QuickSort::partition(vector<int> &nums, int left, int right) {
    int x = nums[right];

    int j = left - 1;
    for (int i = left; i < right; ++i) {
        if (nums[i] < x) {
            j++;
            std::swap(nums[i], nums[j]);
        }
    }

    j++;
    std::swap(nums[right], nums[j]);

    return j;
}

vector<int> QuickSort::sortArray(vector<int> &nums) {
    vector<int> stack;

    stack.push_back(0);
    stack.push_back((int) nums.size() - 1);

    while (!stack.empty()) {
        int stackRight = stack.back();
        stack.pop_back();

        int stackLeft = stack.back();
        stack.pop_back();

        if (stackRight <= stackLeft) {
            continue;
        }

        int mid = partition(nums, stackLeft, stackRight);

        stack.push_back(mid + 1);
        stack.push_back(stackRight);

        stack.push_back(stackLeft);
        stack.push_back(mid - 1);
    }

    return nums;
}

vector<int> CountingSort::sortArray(vector<int> &nums, int minValue, int maxValue) {
    vector<int> count(maxValue - minValue + 1, 0);
    vector<int> result(nums.size());

    for (int num: nums) {
        count[num - minValue]++;
    }

    for (int i = 1; i < count.size(); ++i) {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = (int) nums.size() - 1; i >= 0; --i) {
        result[count[nums[i] - minValue] - 1] = nums[i];
        count[nums[i] - minValue]--;
    }

    return result;
}

vector<int> CountingSort::sortArray(vector<int> &nums) {
    if (nums.empty()) {
        return nums;
    }

    int min = 0;
    int max = 0;
    int i = 0;

    if (nums.size() & 1) {
        min = max = nums[0];
        i = 2;
    } else {
        min = nums[0] <= nums[1] ? nums[0] : nums[1];
        max = nums[0] <= nums[1] ? nums[1] : nums[0];
        i = 3;
    }

    for (; i < nums.size(); i += 2) {
        if (nums[i] > nums[i - 1]) {
            min = nums[i - 1] < min ? nums[i - 1] : min;
            max = nums[i] > max ? nums[i] : max;
        } else {
            min = nums[i] < min ? nums[i] : min;
            max = nums[i - 1] > max ? nums[i - 1] : max;
        }
    }

    return sortArray(nums, min, max);
}

vector<int> InsertSort::sortArray(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }

    return nums;
}

