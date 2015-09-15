/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
class Solution {
public:
    void recoverTree(TreeNode* root) {
        order(root,
              [] (TreeNode *node) { return node->left; },
              [] (TreeNode *node) { return node->right; },
              [] (int last, int current) { return last > current; });
        order(root,
              [] (TreeNode *node) { return node->right; },
              [] (TreeNode *node) { return node->left; },
              [] (int last, int current) { return last < current; });
    }

private:
    void order(
            TreeNode *current,
            function<TreeNode* (TreeNode*)> next1,
            function<TreeNode* (TreeNode*)> next2,
            function<bool (int, int)> need_swap) {
        stack<TreeNode*> stk;
        while (current != nullptr) {
            stk.push(current);
            current = next1(current);
        }
        TreeNode *last = nullptr;
        while (!stk.empty()) {
            current = stk.top();
            stk.pop();
            auto next = next2(current);
            while (next != nullptr) {
                stk.push(next);
                next = next1(next);
            }
            if (last != nullptr && need_swap(last->val, current->val)) {
                swap(last->val, current->val);
            }
            last = current;
        }
    }
};
