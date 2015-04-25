/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto carry(0);
        ListNode dummy(0);
        auto head(&dummy);
        while (l1 != nullptr && l2 != nullptr) {
            auto result(l1->val + l2->val + carry);
            carry = result / 10;
            head->next = new ListNode(result % 10);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        auto x(l1 == nullptr ? l2 : l1);
        while (x != nullptr) {
            auto result(x->val + carry);
            carry = result / 10;
            head->next = new ListNode(result % 10);
            head = head->next;
            x = x->next;
        }
        if (carry != 0) {
            head->next = new ListNode(carry);
            head = head->next;
        }
        return dummy.next;
    }
};
