#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Return {
    ListNode *head;
    ListNode *tail;
    Return(): head(nullptr), tail(nullptr) {}
    Return(ListNode *head, ListNode *tail): head(head), tail(tail) {}
};

Return qsort(ListNode *head) {
    if (head == nullptr) {
        return Return(nullptr, nullptr);
    }
    if (head->next == nullptr) {
        return Return(head, head);
    }
    ListNode *bigger_header(nullptr),
             *smaller_header(nullptr),
             *current(head->next),
             *smaller(nullptr),
             *bigger(nullptr),
             *equal(head),
             *equal_header(head);
    while (current != nullptr) {
        if (current->val < head->val) {
            if (smaller_header == nullptr) {
                smaller_header = current;
            } else {
                smaller->next = current;
            }
            smaller = current;
        } else if (current->val > head->val) {
            if (bigger_header == nullptr) {
                bigger_header = current;
            } else {
                bigger->next = current;
            }
            bigger = current;
        } else {
            equal->next = current;
            equal = current;
        }
        current = current->next;
    }
    if (smaller != nullptr) {
        smaller->next = nullptr;
    }
    if (bigger != nullptr) {
        bigger->next = nullptr;
    }
    Return small = qsort(smaller_header);
    Return big = qsort(bigger_header);
    Return ret(small.head, big.tail);
    equal->next = big.head;
    if (small.head == nullptr) {
        ret.head = equal_header;
    }
    if (big.head == nullptr) {
        ret.tail = equal;
    }
    if (small.tail != nullptr) {
        small.tail->next = equal_header;
    }
    return ret;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return qsort(head).head;
    }
};

int main()
{
    ListNode n1(3), n2(2), n3(1);
    ListNode *head(&n1);
    n1.next = &n2;
    n2.next = &n3;
    Solution s;
    head = s.sortList(head);
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
