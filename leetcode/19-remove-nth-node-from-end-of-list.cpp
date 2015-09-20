
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int counter(-1);
        ListNode *current(head), *np(nullptr);
        while (current != nullptr) {
            ++counter;
            if (np) {
                np = np->next;
            }
            current = current->next;
            if (n == counter) {
                np = head;
            }
        }
        ListNode *to_del(nullptr);
        if (np == nullptr) {
            to_del = head;
            head = head->next;
        } else {
            to_del = np->next;
            np->next = np->next->next;
        }
        delete to_del;
        return head;
    }
};

