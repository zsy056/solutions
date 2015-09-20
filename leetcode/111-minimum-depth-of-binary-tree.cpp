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
    TreeNode* node;
    int level;
    Node(): node(nullptr), level(0) {}
    Node(TreeNode *node, int level): node(node), level(level) {}
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        queue<Node> nodes;
        if (root != nullptr) {
            nodes.push(Node(root, 1));
        }
        while (!nodes.empty()) {
            Node tmp(nodes.front());
            nodes.pop();
            if (tmp.node->left != nullptr) {
                nodes.push(Node(tmp.node->left, tmp.level + 1));
            }
            if (tmp.node->right != nullptr) {
                nodes.push(Node(tmp.node->right, tmp.level + 1));
            }
            if (tmp.node->left == nullptr && tmp.node->right == nullptr) {
                return tmp.level;
            }
        }
        return 0;
    }
};
