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
        auto current = root;
        TreeNode *last = nullptr;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        while (current != nullptr) {
            auto pre = current->left;
            if (pre != nullptr) {
                while (pre->right != nullptr && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    visit(last, current, first, second);
                }
            } else {
                visit(last, current, first, second);
            }
        }
        swap(first->val, second->val);
    }

private:
    void visit(TreeNode* &last, TreeNode* &current, TreeNode* &first, TreeNode* &second) {
        if (last != nullptr && last->val > current->val) {
            if (first == nullptr) {
                first = last;
            }
            second = current;
        }
        last = current;
        current = current->right;
    }
};
