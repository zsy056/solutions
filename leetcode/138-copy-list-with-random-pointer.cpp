/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> cache;
        auto current = head;
        RandomListNode dummy(0);
        auto current_new = &dummy;
        while (current != nullptr) {
            if (cache.find(current) != cache.end()) {
                break;
            }
            auto new_node = new RandomListNode(current->label);
            cache[current] = new_node;
            current_new->next = new_node;
            current_new = new_node;
            current = current->next;
        }
        current = head;
        current_new = dummy.next;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current_new->random = cache[current->random];
            }
            current = current->next;
            current_new = current_new->next;
        }
        return dummy.next;
    }
};
