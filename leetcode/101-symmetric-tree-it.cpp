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
        bool isSymmetric(TreeNode *root) {
            queue<Node> q;
            if (root != nullptr) {
                q.push(Node(root, 1));
            }
            vector<int64_t> level;
            int current(1);
            while (!q.empty()) {
                Node tmp(q.front());
                q.pop();
                if (current != tmp.level) {
                    if (!isSymmetric(level)) {
                        return false;
                    }
                    current = tmp.level;
                    level.clear();
                }
                level.push_back(tmp.node == nullptr ? INT_MAX + 1 : tmp.node->val);
                if (tmp.node != nullptr) {
                    q.push(Node(tmp.node->left, current + 1));
                    q.push(Node(tmp.node->right, current + 1));
                }
            }
            return isSymmetric(level);
        }

        bool isSymmetric(const vector<int64_t> &level) {
            for (auto i=0; i<level.size()/2; ++i) {
                if (level[i] != level[level.size()-1-i]) {
                    return false;
                }
            }
            return true;
        }

};

