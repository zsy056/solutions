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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        queue<Node> nodes;
        if (root != nullptr) {
            nodes.push(Node(root, 1));
        }
        auto current_level = 0;
        while (!nodes.empty()) {
            Node tmp(nodes.front());
            nodes.pop();
            if (tmp.level != current_level) {
                current_level = tmp.level;
                result.push_back(move(vector<int>()));
            }
            if (tmp.node->left != nullptr) {
                nodes.push(Node(tmp.node->left, tmp.level + 1));
            }
            if (tmp.node->right != nullptr) {
                nodes.push(Node(tmp.node->right, tmp.level + 1));
            }
            result.back().push_back(tmp.node->val);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
