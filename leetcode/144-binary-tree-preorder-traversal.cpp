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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if (root != nullptr) {
            stk.push(root);
        }
        while (!stk.empty()) {
            auto parent = stk.top();
            stk.pop();
            result.push_back(parent->val);
            if (parent->right != nullptr) {
                stk.push(parent->right);
            }
            if (parent->left != nullptr) {
                stk.push(parent->left);
            }
        }

        return result;
    }
};
