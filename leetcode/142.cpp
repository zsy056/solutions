#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while (head != nullptr) {
            auto it = set.find(head);
            if (it != set.end()) {
                return *it;
            }
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
