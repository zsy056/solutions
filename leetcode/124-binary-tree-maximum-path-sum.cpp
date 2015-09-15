/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int maxPathSum(TreeNode *root) {
        auto p = _maxPathSum(root);
        return max(p.first, p.second);
    }

private:
    // expandable, non-ex
    pair<int, int> _maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        int exp = root->val;
        int nonexp = root->val;
        pair<int, int> left, right;
        if (root->left != nullptr) {
            left = _maxPathSum(root->left);
            exp = max(exp, root->val + left.first);
            nonexp = max(nonexp, left.second);
            nonexp = max(nonexp, left.first);
        }
        if (root->right != nullptr) {
            right = _maxPathSum(root->right);
            exp = max(exp, root->val + right.first);
            nonexp = max(nonexp, right.second);
            nonexp = max(nonexp, right.first);
        }
        if (root->right != nullptr && root->left != nullptr) {
            nonexp = max(nonexp, right.first + root->val + left.first);
        }
        return {exp, nonexp};
    }
};
