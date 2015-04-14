#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            if (root == nullptr) {
                return vector<int>();
            }
            stack<TreeNode*> stk;
            vector<int> result;
            TreeNode *node = root;
            while (node != nullptr) {
                stk.push(node);
                if (node->left != nullptr) {
                    node = node->left;
                } else if (node->right != nullptr) {
                    node = node->right;
                } else {
                    break;
                }
            }
            node = stk.top();
            result.push_back(node->val);
            stk.pop();
            while (!stk.empty()) {
                auto c_node = stk.top();
                if (c_node->right == node || c_node->right == nullptr) {
                    result.push_back(c_node->val);
                    stk.pop();
                    node = c_node;
                } else {
                    c_node = c_node->right;
                    while (c_node != nullptr) {
                        stk.push(c_node);
                        if (c_node->left != nullptr) {
                            c_node = c_node->left;
                        } else if (c_node->right != nullptr) {
                            c_node = c_node->right;
                        } else {
                            break;
                        }
                    }
                    node = stk.top();
                    result.push_back(node->val);
                    stk.pop();
                }
            }
            return result;
        }
};
