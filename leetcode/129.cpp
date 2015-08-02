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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }

private:
    void sumNumbers(TreeNode *root, int current, int &sum) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            sum += current * 10 + root->val;
            return;
        }
        int next = current * 10 + root->val;
        if (root->left != nullptr) {
            sumNumbers(root->left, next, sum);
        }
        if (root->right != nullptr) {
            sumNumbers(root->right, next, sum);
        }
    }
};
