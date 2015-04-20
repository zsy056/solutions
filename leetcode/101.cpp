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
    bool isSymmetric(TreeNode *root) {
        return root == nullptr ? true : isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *r1, TreeNode *r2) {
        if (r1 == nullptr && r2 == nullptr) {
            return true;
        }
        if (r1 == nullptr || r2 == nullptr) {
            return false;
        }
        return r1->val == r2->val && isMirror(r1->left, r2->right)
            && isMirror(r1->right, r2->left);
    }
};
