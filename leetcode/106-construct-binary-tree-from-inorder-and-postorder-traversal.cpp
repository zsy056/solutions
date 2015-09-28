/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

private:
    TreeNode* buildTree(
            const vector<int> &inorder,
            int ibegin,
            int iend,
            const vector<int> &postorder,
            int pbegin,
            int pend) {
        if (pbegin == pend || ibegin == iend) {
            return nullptr;
        }
        int current = postorder[pend-1];
        auto node = new TreeNode(current);
        int idx = -1;
        for (int i=ibegin; i<iend; ++i) {
            if (inorder[i] == current) {
                idx = i;
                break;
            }
        }
        node->left = buildTree(inorder, ibegin, idx, postorder, pbegin, pbegin+idx-ibegin);
        node->right = buildTree(inorder, idx+1, iend, postorder, pbegin+idx-ibegin, pend-1);

        return node;
    }
};
