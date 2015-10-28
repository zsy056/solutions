/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        if (lists.size() == 2) {
            ListNode dummy(0);
            auto current = &dummy;
            while (lists[0] != nullptr && lists[1] != nullptr) {
                if (lists[0]->val < lists[1]->val) {
                    current->next = lists[0];
                    lists[0] = lists[0]->next;
                } else {
                    current->next = lists[1];
                    lists[1] = lists[1]->next;
                }
                current = current->next;
            }
            current->next = lists[0] == nullptr ? lists[1] : lists[0];
            return dummy.next;
        }
        vector<ListNode*> p1, p2;
        p1.resize(lists.size()/2);
        p2.resize(lists.size() - lists.size()/2);
        copy_n(lists.begin(), lists.size()/2, p1.begin());
        copy_n(lists.begin() + lists.size()/2, lists.size() - lists.size()/2, p2.begin());
        vector<ListNode*> new_lists{mergeKLists(p1), mergeKLists(p2)};
        return mergeKLists(new_lists);
    }
};

