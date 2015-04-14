#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(): val(0), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        int length(0);
        ListNode *current(head);
        while (current != nullptr) {
            ++length;
            current = current->next;
        }
        int half(length / 2 + 0.5);
        ListNode *header2(head);
        auto i = 0;
        while (header2 != nullptr && i<half) {
            ++i;
            header2 = header2->next;
        }
        current = header2;
        header2 = nullptr;
        while (current != nullptr) {
            auto tmp_current(current);
            current = current->next;
            tmp_current->next = header2;
            header2 = tmp_current;
        }
        current = header2;
        while (current != nullptr && head != nullptr && head->next != nullptr) {
            auto tmp_next = head->next;
            head->next = current;
            current = current->next;
            head->next->next = tmp_next;
            head = tmp_next;
            if (head == header2) {
                break;
            }
        }
        if (head != nullptr) {
            head->next = nullptr;
        }
    }
};

int main()
{
    int raw[] = {1, 2, 3, 4};
    auto len = sizeof(raw) / sizeof(raw[0]);
    ListNode n[sizeof(raw)/sizeof(raw[0])];
    for (int i=0; i<len; ++i) {
        n[i].val = raw[i];
        n[i].next = i+1 == len ? nullptr : &n[i+1];
    }
    Solution s;
    s.reorderList(&n[0]);
    auto head = &n[0];
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
