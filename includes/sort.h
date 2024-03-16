//
// Created by YuxinLiu on 2024/01/11.
//

#ifndef LEETCODE_SOLUTION_SORT_H
#define LEETCODE_SOLUTION_SORT_H

#include <vector>
#include <utility>

using std::vector;

vector<std::pair<vector<int>, vector<int>>> sortTestCase();

/*
 * 插入排序
 * */
class InsertSort{
public:
    static vector<int> sortArray(vector<int> &nums);
};

/*
 * 原地归并, 不使用额外辅助空间而是使用内部空间作为缓存, 比朴素归并排序的时间复杂度有常数项差异
 */
class InPlaceMergeSort {
private:
    static void mergeArray(vector<int> &nums, size_t leftBegin, size_t leftEnd, size_t rightBegin, size_t rightEnd);

public:
    static void sortArray(vector<int> &nums, size_t unsortedBegin, size_t sortedBegin, size_t sortedEnd);

    static vector<int> sortArray(vector<int> &nums);
};

/*
 * 朴素的归并排序,需要使用额外的辅助空间
 */
class PlainMergeSort {
private:
    static void mergeArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t mid, size_t right);

public:
    static void sortArray(vector<int> &nums, vector<int> &buffer, size_t left, size_t right);

    static vector<int> sortArray(vector<int> &nums);
};

class HeapSort {
private:
    int heapSize = 0;

    static int parent(int i) { return (i - 1) >> 1; }

    static int leftChild(int i) { return (i << 1) + 1; }

    static int rightChild(int i) { return (i << 1) + 2; }

    void maxHeapify(vector<int> &nums, int i);

    void buildMaxHeap(vector<int> &nums);

public:
    vector<int> sortArray(vector<int> &nums);
};

class QuickSort {
private:
    static int partition(vector<int> &nums, int left, int right);

public:
    static void sortArray(vector<int> &nums, int left, int right);

    static vector<int> sortArray(vector<int> &nums);
};

class CountingSort {
private:
    int valueScale = 0;
public:
    explicit CountingSort(int x) : valueScale(x) {}

    vector<int> sortArray(vector<int> &nums);
};

#endif //LEETCODE_SOLUTION_SORT_H
