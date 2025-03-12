#include "catch_amalgamated.hpp"

#include "ListNode.h"
using namespace std;

 class ReverseNodesInKGroup
 {
     ListNode* reverse(ListNode* const start, const ListNode* const end){
         ListNode *head = start;
         ListNode *tail = start;

         while (tail->next != end){
             ListNode *next = tail->next;
             tail->next = tail->next->next;
             next->next = head;
             head = next;
         }

         return head;
     }

 public:
     ListNode* reverseKGroup(ListNode* head, const int k) {
         ListNode dummy;
         dummy.next = head;

         int cnt;
         ListNode *p;
         ListNode *prev = &dummy;

         for (cnt = 0, p = prev; p != nullptr; p = p->next, ++cnt){
             if (cnt == k){
                 ListNode *new_last = prev->next;
                 prev->next = reverse(prev->next, p->next);
                 prev = new_last;
                 p = new_last;
                 cnt = 0;
             }
         }

         return dummy.next;
     }
 };

TEST_CASE("ReverseNodesInKGroup", "[ReverseNodesInKGroup]")
{
    ListNode* head;

    head = createListNode({1,2,3,4,5});
    head = ReverseNodesInKGroup().reverseKGroup(head, 2);
    REQUIRE(extractList(head) == vector<int>{2,1,4,3,5});
    releaseListNode(head);

    head = createListNode({1,2,3,4,5});
    head = ReverseNodesInKGroup().reverseKGroup(head, 3);
    REQUIRE(extractList(head) == vector<int>{3,2,1,4,5});
    releaseListNode(head);
}