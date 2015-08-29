/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = 0;
        auto current = root->left;
        while (current != nullptr) {
            ++left_height;
            current = current->left;
        }
        current = root->right;
        int right_height = 0;
        while (current != nullptr) {
            ++right_height;
            current = current->right;
        }
        if (left_height == right_height) {
            return pow(2, left_height + 1) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

};
