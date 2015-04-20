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
    TreeNode *node;
    int level;
    Node(): node(nullptr), level(0) {}
    Node(TreeNode *node, int level): node(node), level(level) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        queue<Node> q;
        if (root != nullptr) {
            q.push(Node(root, 1));
        }
        int current(0);
        while (!q.empty()) {
            Node tmp(q.front());
            q.pop();
            current = tmp.level;
            if (tmp.node->left != nullptr) {
                q.push(Node(tmp.node->left, current + 1));
            }
            if (tmp.node->right != nullptr) {
                q.push(Node(tmp.node->right, current + 1));
            }
        }
        return current;
    }
};
