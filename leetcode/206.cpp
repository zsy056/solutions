/*
Reverse a singly linked list.

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto p1 = head;
        auto p2 = head->next;
        head->next = nullptr;
        while (p2 != nullptr) {
            auto tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }

        return p1;
    }
};
