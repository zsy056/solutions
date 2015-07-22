/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using after_rev_t = tuple<ListNode*, ListNode*>;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = len(head);
        if (n <= 1) {
            return true;
        }
        auto after_rev = rev(head, n / 2);
        auto left = get<0>(after_rev);
        auto right = get<1>(after_rev);
        if (n % 2 == 1) {
            right = right->next;
        }
        return equals(left, right);
    }

private:
    bool equals(ListNode *l1, ListNode *l2) {
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1 == nullptr && l2 == nullptr;
    }

    int len(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            ++length;
            head = head->next;
        }
        return length;
    }

    after_rev_t rev(ListNode* head, int n) {
        if (head == nullptr) {
            return make_tuple(nullptr, nullptr);
        }
        auto p1 = head;
        auto p2 = head->next;
        p1->next = nullptr;
        for (int i=1; i<n; ++i) {
            auto tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return make_tuple(p1, p2);
    }
};
