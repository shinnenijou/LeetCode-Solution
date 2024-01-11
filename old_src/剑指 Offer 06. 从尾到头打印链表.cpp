/*
 * 剑指 Offer 06. 从尾到头打印链表
 */

// @lc code=start

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include<vector>
using std::vector;

class Solution {
private:
    vector<int> ret;
public:
    const vector<int>& reversePrint(ListNode* head) {
        if(!head) return ret;

        reversePrint(head->next);
        ret.push_back(head->val);

        return ret;
    }
};
// @lc code=end
