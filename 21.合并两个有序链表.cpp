/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2) return list1?list1:list2;
        ListNode *head = list1->val < list2->val ? list1 : list2;
        ListNode *sub_node = list1->val < list2->val ? list2 : list1;
        ListNode *cur_node = head;
        while(sub_node && cur_node){
            if(!cur_node->next || sub_node->val < cur_node->next->val){
                ListNode *temp = sub_node;
                sub_node = cur_node->next;
                cur_node->next = temp;
            }
            cur_node = cur_node->next;
        }
        return head;
    }
};
// @lc code=end

