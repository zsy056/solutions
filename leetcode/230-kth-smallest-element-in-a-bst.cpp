/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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

using result_t = tuple<int, bool>;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        num = 0;
        tk = k;
        auto result = kthSmallest(root);
        return get<0>(result);
    }

    result_t kthSmallest(TreeNode* root) {
        if (root == nullptr) {
            return make_tuple(0, false);
        }
        auto left_result = kthSmallest(root->left);
        if (get<1>(left_result)) {
            return left_result;
        }
        ++num;
        if (num == tk) {
            return make_tuple(root->val, true);
        }
        auto right_result = kthSmallest(root->right);
        if (get<1>(right_result)) {
            return right_result;
        }
        return make_tuple(0, false);
    }

private:
    int num;
    int tk;
};
