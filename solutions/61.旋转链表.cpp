#include "catch_amalgamated.hpp"
#include "ListNode.h"

#include "vector"
using namespace std;

class RotateList {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode dummy(0, head);

        int size = 0;
        for (ListNode* node = head; node != nullptr; node = node->next) ++size;
        if (size == 0) return head;
        k %= size;
        if (k == 0) return head;

        ListNode* node = head;

        for (int i = 0; i < size - k - 1; ++i) node = node->next;
        dummy.next = node->next;
        node->next = nullptr;

        node = dummy.next;
        for (int i = size - k; i < size - 1; ++i) node = node->next;
        node->next = head;
        return dummy.next;
    }
};

TEST_CASE("RotateList", "[RotateList]")
{
    ListNode* head;

    head = createListNode({1,2,3,4,5});
    head = RotateList().rotateRight(head, 2);
    REQUIRE(extractList(head) == vector<int>{4,5,1,2,3});
    releaseListNode(head);

    head = createListNode({0,1,2});
    head = RotateList().rotateRight(head, 4);
    REQUIRE(extractList(head) == vector<int>{2,0,1});
    releaseListNode(head);
}