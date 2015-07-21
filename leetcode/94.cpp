/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        stack<TreeNode*> stk;
        auto current = root;
        while (current != nullptr) {
            stk.push(current);
            current = current->left;
        }
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            result.push_back(node->val);
            auto child = node->right;
            while (child != nullptr) {
                stk.push(child);
                child = child->left;
            }
        }

        return result;
    }
};
