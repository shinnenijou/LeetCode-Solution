#ifndef LEETCODE_SOLUTION_LIST_H
#define LEETCODE_SOLUTION_LIST_H

#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(const std::vector<int>& values);
void deleteList(ListNode *head);
std::vector<int> createVector(ListNode *head);


class AddTwoNumbers{
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif //LEETCODE_SOLUTION_LIST_H
