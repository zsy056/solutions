

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr1(head), *ptr2(head);
        while (ptr1 != nullptr && ptr2 != nullptr) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
            if (ptr2 == nullptr) {
                break;
            }
            ptr2 = ptr2->next;
            if (ptr2 == ptr1) {
                break;
            }
        }
        return ptr2 == nullptr ? false : true;
    }
};
