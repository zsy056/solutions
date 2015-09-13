/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

using item_t = pair<TreeLinkNode*, int>;

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        queue<item_t> items;
        items.push({root, 0});
        int current_level = 0;
        TreeLinkNode *last = nullptr;
        while (!items.empty()) {
            auto item = items.front();
            auto node = item.first;
            if (last != nullptr && current_level == item.second) {
                last->next = node;
            }
            current_level = item.second;
            last = node;
            items.pop();
            if (node->left != nullptr) {
                items.push({node->left, current_level + 1});
            }
            if (node->right != nullptr) {
                items.push({node->right, current_level + 1});
            }
        }
    }
};

