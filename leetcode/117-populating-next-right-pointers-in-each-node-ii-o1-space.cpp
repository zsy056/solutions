/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        auto level = root;
        while (level != nullptr) {
            auto current = level;
            while (current != nullptr) {
                if (current->left != nullptr && current->right != nullptr)
                    current->left->next = current->right;
                auto next = current->next;
                while (next != nullptr && next->left == nullptr && next->right == nullptr)
                    next = next->next;
                auto next_peer = next == nullptr ? nullptr : (next->left == nullptr ? next->right : next->left);
                if (current->left != nullptr && current->right == nullptr)
                    current->left->next = next_peer;
                if (current->right != nullptr)
                    current->right->next = next_peer;
                current = next;
            }
            while (level != nullptr && level->left == nullptr && level->right == nullptr)
                level = level->next;
            level = level == nullptr ? nullptr : (level->left == nullptr ? level->right : level->left);
        }
    }
};
