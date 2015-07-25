/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        stack<TreeNode*> stk;
        while (root->left != nullptr) {
            stk.push(root->right);
            root->right = root->left;
            auto tmp = root;
            root = root->left;
            tmp->left = nullptr;
        }
        stk.push(root->right);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            root->right = node;
            if (node == nullptr) {
                continue;
            }
            while (node->left != nullptr) {
                stk.push(node->right);
                node->right = node->left;
                auto tmp = node;
                node = node->left;
                tmp->left = nullptr;
            }
            stk.push(node->right);
            root = node;
        }
    }
};
