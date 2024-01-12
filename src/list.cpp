#include "list.h"

ListNode *createList(const std::vector<int>& values){
    ListNode *head = nullptr;

    for (auto iter = values.rbegin(); iter != values.rend(); ++iter){
        auto curr = new ListNode(*iter, head);
        head = curr;
    }

    return head;
}

void deleteList(ListNode *head){
    while (!head){
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}
