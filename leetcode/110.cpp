/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Result {
    bool balanced;
    int depth;
    Result(): balanced(true), depth(0) {}
    Result(bool balanced, int depth = 0): balanced(balanced), depth(depth) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return _isBalanced(root).balanced;
    }
private:
    Result _isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return Result();
        }
        Result left = _isBalanced(root->left);
        if (!left.balanced) {
            return Result(false);
        }
        Result right = _isBalanced(root->right);
        if (!right.balanced) {
            return Result(false);
        }
        if (abs(right.depth - left.depth) > 1) {
            return Result(false);
        }
        return Result(true, 1 + max(left.depth, right.depth));
    }
};
