//
// Created by YuxinLiu on 2024/01/11.
//

#ifndef LEETCODE_SOLUTION_SORT_H
#define LEETCODE_SOLUTION_SORT_H

#include <vector>
#include <utility>

std::vector<std::pair<std::vector<int>,std::vector<int>>> sortTestCase(const std::vector<std::vector<int>>& cases);

class InPlaceMergeSort {
private:
    static void _mergeArray(std::vector<int> &nums, size_t leftBegin, size_t leftEnd, size_t rightBegin, size_t rightEnd);

    static void _sortArray(std::vector<int> &nums, size_t unsortedBegin, size_t sortedBegin, size_t sortedEnd);

public:
    static std::vector<int> sortArray(std::vector<int> &nums);
};

class PlainMergeSort {
private:
    static void _mergeArray(std::vector<int> &nums, std::vector<int> &buffer, size_t left, size_t mid, size_t right);

    static void _sortArray(std::vector<int> &nums, std::vector<int> &buffer, size_t left, size_t right);

public:
    static std::vector<int> sortArray(std::vector<int> &nums);
};


#endif //LEETCODE_SOLUTION_SORT_H
