/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        auto node = head;
        while (node != nullptr) {
            ++len;
            node = node->next;
        }
        return sortedListToBST(head, 0, len);
    }

private:
    TreeNode* sortedListToBST(ListNode* &head, int begin, int end) {
        if (begin == end) {
            return nullptr;
        }
        int mid = (begin + end) / 2;
        auto node = new TreeNode(0);
        node->left = sortedListToBST(head, begin, mid);
        node->val = head->val;
        head = head->next;
        node->right = sortedListToBST(head, mid+1, end);

        return node;
    }
};
