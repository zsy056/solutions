/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* buildTree(
            const vector<int> &preorder,
            int pbegin,
            int pend,
            const vector<int> &inorder,
            int ibegin,
            int iend
            ) {
        if (pbegin == pend || ibegin == iend) {
            return nullptr;
        }
        int current = preorder[pbegin];
        int iidx = -1;
        for (int i=ibegin; i<iend; ++i) {
            if (inorder[i] == current) {
                iidx = i;
                break;
            }
        }
        auto node = new TreeNode(current);
        node->left = buildTree(preorder, pbegin+1, pend, inorder, ibegin, iidx);
        node->right = buildTree(preorder, pbegin+1+iidx-ibegin, pend, inorder, iidx+1, iend);
        return node;
    }
};
