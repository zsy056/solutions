/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.

 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
        auto original(head);
        while (head != nullptr) {
            auto current(head->val);
            while (head->next != nullptr && head->next->val == current) {
                head->next = head->next->next;
                // delete head->next ?
            }
            head = head->next;
        }
        return original;
    }
};
