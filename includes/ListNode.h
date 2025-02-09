//
// Created by YuxinLiu on 2025/2/9.
//

#ifndef LISTNODE_H
#define LISTNODE_H

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    explicit ListNode(const int x) : val(x), next(nullptr)
    {
    }

    ListNode(const int x, ListNode* next) : val(x), next(next)
    {
    }
};
#endif //LISTNODE_H
