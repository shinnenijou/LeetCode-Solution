#include "catch_amalgamated.hpp"
#include "ListNode.h"

/*
 * Recursive
 */
struct SwapNodeInPairs_1 {
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode* next = head->next;
        head->next = next->next;
        next->next = head;
        head->next = swapPairs(head->next);
        return next;
    }
};

struct SwapNodeInPairs_2
{
    ListNode* swapPairs(ListNode* head) {
        ListNode vitualHead(0, head);
        ListNode *prev = &vitualHead;

        for(ListNode* node = head; node != nullptr && node->next != nullptr; node = node->next)
        {
            ListNode* next = node->next;
            node->next = next->next;
            next->next = node;
            prev->next = next;
            prev = node;
        }

        return vitualHead.next;
    }
};

TEST_CASE("SwapNodeInPairs1", "[SwapNodeInPairs]")
{
    ListNode* head = nullptr;

    head = createListNode({1, 2, 3, 4});
    head = SwapNodeInPairs_1().swapPairs(head);
    REQUIRE(checkList(head, {2, 1, 4, 3}) == true);
    releaseListNode(head);


    head = createListNode({1, 2, 3, 4, 5});
    head = SwapNodeInPairs_1().swapPairs(head);
    REQUIRE(checkList(head, {2, 1, 4, 3, 5}) == true);
    releaseListNode(head);
}

TEST_CASE("SwapNodeInPairs2", "[SwapNodeInPairs]")
{
    ListNode* head = nullptr;

    head = createListNode({1, 2, 3, 4});
    head = SwapNodeInPairs_2().swapPairs(head);
    REQUIRE(checkList(head, {2, 1, 4, 3}) == true);
    releaseListNode(head);


    head = createListNode({1, 2, 3, 4, 5});
    head = SwapNodeInPairs_2().swapPairs(head);
    REQUIRE(checkList(head, {2, 1, 4, 3, 5}) == true);
    releaseListNode(head);
}
