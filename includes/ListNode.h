//
// Created by YuxinLiu on 2025/2/9.
//

#ifndef LISTNODE_H
#define LISTNODE_H

#include <initializer_list>
#include <stack>
#include <vector>

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

inline ListNode* createListNode(std::initializer_list<int> list)
{
    std::stack<int> stack;
    ListNode* node = nullptr;

    for (int i : list)
    {
        stack.push(i);
    }

    while (!stack.empty())
    {
        node = new ListNode(stack.top(), node);
        stack.pop();
    }

    return node;
}

inline void releaseListNode(ListNode* node)
{
    while (node != nullptr)
    {
        ListNode* next = node->next;
        delete node;
        node = next;
    }
}

inline bool checkList(ListNode* node, std::initializer_list<int> list)
{
    auto it = list.begin();

    while (it != list.end() && node != nullptr)
    {
        if (*it != node->val) return false;
        ++it;
        node = node->next;
    }

    return it == list.end() && node == nullptr;;
}

inline std::vector<int> extractList(ListNode* node)
{
    std::vector<int> ret{};

    for (const ListNode* current = node; current != nullptr; current = current->next)
    {
        ret.push_back(current->val);
    }

    return ret;
}
#endif //LISTNODE_H
