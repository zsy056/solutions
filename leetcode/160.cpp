struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto len1(0), len2(0);
        ListNode *a(headA), *b(headB);
        while (a != nullptr) {
            ++len1;
            a = a->next;
        }
        while (b != nullptr) {
            ++len2;
            b = b->next;
        }
        a = headA; b = headB;
        if (len2 > len1) {
            for (auto i=0; i<len2-len1; ++i) {
                b = b->next;
            }
        } else if (len2 < len1) {
            for (auto i=0; i<len1-len2; ++i) {
                a = a->next;
            }
        }
        while (a != nullptr && b != nullptr) {
            if (a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};
