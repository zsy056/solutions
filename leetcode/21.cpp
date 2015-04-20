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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head(nullptr), *current(nullptr);
        while (l1 != nullptr && l2 != nullptr) {
            auto to_insert = l1->val < l2->val ? l1 : l2;
            if (l1->val < l2->val) {
                l1 = l1->next;
            } else {
                l2 = l2->next;
            }
            if (head == nullptr) {
                head = to_insert;
            } else {
                current->next = to_insert;
            }
            current = to_insert;
        }
        while (l1 != nullptr || l2 != nullptr) {
            auto to_insert = l1 == nullptr ? l2 : l1;
            if (l1 == nullptr) {
                l2 = l2->next;
            } else {
                l1 = l1->next;
            }
            if (head == nullptr) {
                head = to_insert;
            } else {
                current->next = to_insert;
            }
            current = to_insert;
        }

        return head;
    }
};
