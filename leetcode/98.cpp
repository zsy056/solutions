/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

using result_t = tuple<bool, int64_t>;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto result = check(root, INT64_MIN);
        return get<0>(result);
    }
private:
    result_t check(TreeNode *root, int64_t last) {
        if (root == nullptr) {
            return make_tuple(true, last);
        }
        auto result = check(root->left, last);
        auto is_valid = get<0>(result);
        auto new_last = get<1>(result);
        if (!is_valid || new_last >= root->val) {
            return make_tuple(false, INT_MAX);
        }
        return check(root->right, root->val);
    }
};
