/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dummy(0);
        int current_count = 1;
        auto current = head;
        auto to_check = head->next;
        auto tail = &dummy;

        while (to_check != nullptr) {
            if (current->val == to_check->val) {
                ++current_count;
            } else if (current->val < to_check->val) {
                if (current_count == 1) {
                    tail->next = current;
                    tail = tail->next;
                }
                current = to_check;
                current_count = 1;
            }
            to_check = to_check->next;
        }
        if (current_count == 1) {
            tail->next = current;
            tail = tail->next;
        }
        tail->next = nullptr;

        return dummy.next;
    }
};
