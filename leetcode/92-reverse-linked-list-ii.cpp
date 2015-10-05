/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        auto current = &dummy;
        for (int i=1; i<m; ++i) {
            current->next = head;
            current = current->next;
            head = head->next;
        }
        current->next = reverse(head, n-m+1);
        return dummy.next;
    }
private:
    ListNode *reverse(ListNode *node, int n) {
        if (n == 1) {
            return node;
        }
        auto p1 = node;
        auto p2 = node->next;
        for (int i=1; i<n; ++i) {
            auto tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        node->next = p2;
        return p1;
    }
};
