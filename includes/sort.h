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
        static void _mergeArray(vector<int> &nums, int left, int quarter, int mid, int right);
        static void _sortArray(vector<int> &nums, int left, int right);
    public:
        static vector<int> sortArray(vector<int> &nums);
    };
}

namespace PlainMergeSort{
    class Solution{
    private:
        static void _mergeArray(vector<int> &nums, vector<int> &buffer, int left, int mid, int right);
        static void _sortArray(vector<int> &nums, vector<int> &buffer, int left, int right);
    public:
        static vector<int> sortArray(std::vector<int> &nums);
    };
}


#endif //LEETCODE_SOLUTION_SORT_H
