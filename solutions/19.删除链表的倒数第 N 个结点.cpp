#include "catch_amalgamated.hpp"
#include "ListNode.h"

#include <vector>

using namespace std;

class RemoveNthNodeFromEndOfList
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy(0, head);
        const ListNode* node = &dummy;

        for ( ; n >= 0 && node != nullptr; --n, node = node->next) {}

        if (n >= 0) return dummy.next;

        ListNode* prev = &dummy;

        for (; node != nullptr; node = node->next, prev = prev->next) {}

        prev->next = prev->next->next;

        return dummy.next;
    }
};


TEST_CASE("RemoveNthNodeFromEndOfList", "[RemoveNthNodeFromEndOfList]")
{
    ListNode* head;
    vector<int> output{};

    head = createListNode({1, 2, 3, 4, 5});
    output = extractList(RemoveNthNodeFromEndOfList().removeNthFromEnd(head, 2));
    REQUIRE(output == vector<int>{1, 2, 3, 5});
    releaseListNode(head);

    head = createListNode({1});
    output = extractList(RemoveNthNodeFromEndOfList().removeNthFromEnd(head, 1));
    REQUIRE(output == vector<int>{});
    releaseListNode(head);

    head = createListNode({1, 2});
    output = extractList(RemoveNthNodeFromEndOfList().removeNthFromEnd(head, 1));
    REQUIRE(output == vector<int>{1});
    releaseListNode(head);

    head = createListNode({1});
    output = extractList(RemoveNthNodeFromEndOfList().removeNthFromEnd(head, 2));
    REQUIRE(output == vector<int>{1});
    releaseListNode(head);
}
