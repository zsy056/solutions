/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        auto current = &dummy;
        while (true) {
            auto kth = getKth(current, k);
            if (kth == nullptr) {
                break;
            }
            auto k1th = kth->next;
            auto new_head = reverse(current->next, k);
            auto new_tail = current->next;
            current->next = new_head;
            current = new_tail;
            current->next = k1th;
        }
        return dummy.next;
    }
private:
    ListNode *reverse(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        auto p1 = head;
        auto p2 = head->next;
        int i = 1;
        while (p2 != nullptr && i<k) {
            auto b = p2;
            p2 = p2->next;
            b->next = p1;
            p1 = b;
            ++i;
        }
        return p1;
    }


    ListNode* getKth(ListNode *head, int k) {
        auto kth = head;
        for (int i=0; i<k && kth; ++i) {
            kth = kth->next;
        }
        return kth;
    }
};
