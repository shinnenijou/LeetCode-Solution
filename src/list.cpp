#include "list.h"

ListNode *createList(const std::vector<int> &values) {
    ListNode *head = nullptr;

    for (auto iter = values.rbegin(); iter != values.rend(); ++iter) {
        auto curr = new ListNode(*iter, head);
        head = curr;
    }

    return head;
}

void deleteList(ListNode *head) {
    while (head) {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

std::vector<int> createVector(ListNode *head) {
    std::vector<int> ret;

    while (head) {
        ret.push_back(head->val);
        head = head->next;
    }

    return ret;
}

ListNode *AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    auto *head = new ListNode;
    ListNode *curr = head;

    while (l1 && l2) {
        int value = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        auto *temp = new ListNode(value);
        curr->next = temp;
        curr = temp;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        int value = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        auto *temp = new ListNode(value);
        curr->next = temp;
        curr = temp;
        l1 = l1->next;
    }

    while (l2) {
        int value = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        auto *temp = new ListNode(value);
        curr->next = temp;
        curr = temp;
        l2 = l2->next;
    }

    if (carry){
        curr->next = new ListNode(carry);
    }

    ListNode *ret = head->next;
    delete head;
    return ret;
}

ListNode *ReverseLinkedList::_reverseListRecursive(ListNode *head) {
    if (!head->next){
        newHead = head;
    }
    else{
        ListNode *prev = _reverseListRecursive(head->next);
        prev->next = head;
    }

    head->next = nullptr;
    return head;
}

ListNode *ReverseLinkedList::reverseListRecursive(ListNode *head) {
    if (!head) return nullptr;
    _reverseListRecursive(head);
    return newHead;
}

ListNode *ReverseLinkedList::reverseListIterative(ListNode *head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}
