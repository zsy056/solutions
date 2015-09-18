/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
        auto path_p = get_path(root, p);
        auto path_q = get_path(root, q);
        while (path_p.size() > path_q.size()) {
            path_p.pop_back();
        }
        while (path_q.size() > path_p.size()) {
            path_q.pop_back();
        }
        while (!path_p.empty()) {
            if (path_q.back() == path_p.back()) {
                return path_p.back();
            } else {
                path_p.pop_back();
                path_q.pop_back();
            }
        }
        return nullptr;
    }

    vector<TreeNode*> get_path(TreeNode *root, TreeNode *target) {
        auto current = root;
        auto val = target->val;
        vector<TreeNode*> path;
        while (current != nullptr) {
            path.push_back(current);
            if (current->val > target->val) {
                current = current->left;
            } else if (current->val < target->val) {
                current = current->right;
            } else {
                break;
            }
        }
        return path;
    }
};
