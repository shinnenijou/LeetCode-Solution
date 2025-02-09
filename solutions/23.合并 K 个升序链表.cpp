#include <vector>
#include <queue>
#include <algorithm>
#include "ListNode.h"
#include "catch_amalgamated.hpp"

using namespace std;

class MergeKSortedLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        lists.erase(remove_if(lists.begin(), lists.end(), [](ListNode* l) { return l == nullptr;}), lists.end());
        priority_queue queue{[](ListNode* l, ListNode* r){return l->val > r->val;}, lists};

        ListNode head;

        for (ListNode* node = &head; !queue.empty(); queue.pop())
        {
            node->next = queue.top();
            node = queue.top();
            if (node->next) queue.push(node->next);
        }

        return head.next;
    }
};

TEST_CASE("MergeKSortedLists", "[MergeKSortedLists]")
{
    vector<ListNode*> lists;
    lists.push_back(createListNode({1,4,5}));
    lists.push_back(createListNode({1,3,4}));
    lists.push_back(createListNode({2,6}));
    lists.push_back(createListNode({}));
    ListNode* head = MergeKSortedLists().mergeKLists(lists);
    REQUIRE(checkList(head, {1,1,2,3,4,4,5,6}));
    releaseListNode(head);
}