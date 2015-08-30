/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        get_path(root, p, path1);
        get_path(root, q, path2);
        int i = 0;
        for (; i<path1.size() && i<path2.size(); ++i) {
            if (path1[i] != path2[i]) {
                break;
            }
        }
        return path1[i-1];
    }

private:
    bool get_path(TreeNode *root, TreeNode *target, vector<TreeNode*> &path) {
        if (root == nullptr) {
            return false;
        }
        path.push_back(root);
        if (root == target) {
            return true;
        }
        auto r = get_path(root->left, target, path)
                 || get_path(root->right, target, path);
        if (!r) {
            path.pop_back();
        }
        return r;
    }
};
