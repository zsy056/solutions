#include <climits>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *next_to_insert = head->next;
        head->next = nullptr;
        while (next_to_insert != nullptr) {
            ListNode *to_insert = next_to_insert;
            ListNode dummy(INT_MIN);
            dummy.next = head;
            ListNode *current = &dummy;
            next_to_insert = next_to_insert->next;
            while (current->next != nullptr && current->next != to_insert && current->next->val < to_insert->val) {
                current = current->next;
            }
            auto tail = current->next;
            current->next = to_insert;
            to_insert->next = tail;
            head = dummy.next;
        }
        return head;
    }
};
