/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "ListNode.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode *head = new ListNode(), *cur_node = head;
        int carry = 0;
        while(l1 && l2){
            int digit = l1->val + l2->val + carry;
            carry = digit /10;
            cur_node->next = new ListNode(digit % 10);
            cur_node = cur_node->next;
            l1 = l1->next, l2 = l2->next;
        }
        while(l1){
            int digit = l1->val + carry;
            carry = digit /10;
            cur_node->next = new ListNode(digit % 10);
            cur_node = cur_node->next;
            l1 = l1->next;
        }
        while(l2){
            int digit = l2->val + carry;
            carry = digit /10;
            cur_node->next = new ListNode(digit % 10);
            cur_node = cur_node->next;
            l2 = l2->next;
        }

        if(carry){
            cur_node->next = new ListNode(carry % 10);
        }
        ListNode *p_temp = head;
        head = head->next;
        delete p_temp;
        return head;
    }
};
// @lc code=end

