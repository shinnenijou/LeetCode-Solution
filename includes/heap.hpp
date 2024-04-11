//
// Created by littl on 14/3/2024.
//

#ifndef LEETCODE_SOLUTION_HEAP_HPP
#define LEETCODE_SOLUTION_HEAP_HPP

#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>

using std::vector;
using std::pair;

template<class KeyType, class ValueType>
class PriorityQueue {
private:
    static inline int parent(int i) { return ((i - 1) >> 1); }

    static inline int leftChild(int i) { return (i >> 1) + 1; }

    static inline int rightChild(int i) { return (i >> 1) + 2; }

    void maxHeapify(int i);

protected:
    vector<pair<KeyType, ValueType>> heap;
    int heapSize = 0;

public:
    void push(KeyType key, ValueType value);

    void pop();

    const pair<KeyType, ValueType> &top() const;
};

template<class KeyType, class ValueType>
void PriorityQueue<KeyType, ValueType>::pop() {
    if (heapSize == 0) {
        throw std::out_of_range("PriorityQueue underflow");
    }

    heapSize--;
    std::swap(heap[0], heap[heapSize]);
    maxHeapify(0);
}

template<class KeyType, class ValueType>
const pair<KeyType, ValueType> &PriorityQueue<KeyType, ValueType>::top() const {
    return heap[0];
}

template<class KeyType, class ValueType>
void PriorityQueue<KeyType, ValueType>::maxHeapify(int i) {
    int leftChildIndex = leftChild(i);
    int rightChildIndex = rightChild(i);

    if (leftChildIndex >= heapSize) {
        return;
    }

    int largestIndex = heap[leftChildIndex].first > heap[i].first ? leftChildIndex : i;

    if (rightChildIndex < heapSize) {
        largestIndex = heap[rightChildIndex].first > heap[largestIndex].first ? rightChildIndex : largestIndex;
    }

    if (largestIndex != i) {
        std::swap(heap[i], heap[largestIndex]);
        maxHeapify(largestIndex);
    }
}

template<class KeyType, class ValueType>
void PriorityQueue<KeyType, ValueType>::push(KeyType key, ValueType value) {
    heap.emplace_back(key, value);
    heapSize++;

    int currentIndex = heapSize - 1;

    while (currentIndex != 0) {
        std::swap(heap[parent(currentIndex)], heap[currentIndex]);
        currentIndex = parent(currentIndex);
        maxHeapify(currentIndex);
    }
}

#endif //LEETCODE_SOLUTION_HEAP_HPP
