//
// Created by YuxinLiu on 2024/01/11.
//

#ifndef LEETCODE_SOLUTION_SORT_H
#define LEETCODE_SOLUTION_SORT_H

#include <vector>
using std::vector;

namespace InPlaceMergeSort{
    class Solution{
    private:
        static void _mergeArray(vector<int> &nums, size_t left, size_t quarter, size_t mid, size_t right);
        static void _sortArray(vector<int> &nums, size_t left, size_t right);
    public:
        static vector<int> sortArray(vector<int> &nums);
    };
}

namespace PlainMergeSort{
    class Solution{
    private:
        static void _mergeArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t mid, size_t right);
        static void _sortArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t right);
    public:
        static vector<int> sortArray(std::vector<int> &nums);
    };
}


#endif //LEETCODE_SOLUTION_SORT_H
