/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        auto n = len(head);
        if (n <= 1) {
            return head;
        }
        k = k % n;
        if (k == 0)
        {
            return head;
        }
        int j = n - k;
        auto head2 = head;
        for (int i=0; i<j-1; ++i) {
            head2 = head2->next;
        }
        auto tail = head2;
        head2 = head2->next;
        tail->next = nullptr;
        tail = head2;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }
        if (tail != nullptr) {
            tail->next = head;
        }
        return head2;
    }

    int len(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            ++length;
            head = head->next;
        }
        return length;
    }
};
