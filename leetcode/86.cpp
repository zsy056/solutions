/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode smaller(0);
        ListNode rest(0);
        auto current_smaller = &smaller;
        auto current_rest = &rest;

        while (head != nullptr) {
            if (head->val < x) {
                current_smaller->next = head;
                current_smaller = current_smaller->next;
            } else {
                current_rest->next = head;
                current_rest = current_rest->next;
            }
            head = head->next;
        }

        current_rest->next = nullptr;
        current_smaller->next = rest.next;
        return smaller.next;
    }
};
