/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (sum == root->val && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return (root->left != nullptr && hasPathSum(root->left, sum - root->val))
            || (root->right != nullptr && hasPathSum(root->right, sum - root->val));
    }
};
