/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node {
    int level;
    TreeNode *node;
    Node(int level, TreeNode *node): level(level), node(node) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        queue<Node> q;
        auto currentLevel(0);
        if (root != nullptr) {
            q.push(Node(1, root));
        }
        while (!q.empty()) {
            auto tmp(q.front());
            q.pop();
            if (tmp.level != currentLevel) {
                result.push_back(tmp.node->val);
                currentLevel = tmp.level;
            }
            if (tmp.node->right != nullptr) {
                q.push(Node(tmp.level + 1, tmp.node->right));
            }
            if (tmp.node->left != nullptr) {
                q.push(Node(tmp.level + 1, tmp.node->left));
            }
        }
        return result;
    }
};
