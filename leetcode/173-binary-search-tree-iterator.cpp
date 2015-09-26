#include <stack>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode;

class BSTIterator {
public:
    BSTIterator(TreeNode *root): nodes(), current(nullptr) {
        auto next_node = root;
        while (next_node != nullptr) {
            nodes.push(next_node);
            next_node = next_node->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        stack<TreeNode*> working_nodes(nodes);
        auto result = tryGetNext(working_nodes);
        return result != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        auto result = tryGetNext(nodes);
        current = result;
        return result->val;
    }
private:
    stack<TreeNode*> nodes;
    TreeNode *current;

    TreeNode *tryGetNext(stack<TreeNode*> &working_nodes) {
        if (working_nodes.empty()) {
            return nullptr;
        }
        auto working_current = working_nodes.top();
        working_nodes.pop();
        if (working_current->right != nullptr) {
            auto next_node = working_current->right;
            while (next_node != nullptr) {
                working_nodes.push(next_node);
                next_node = next_node->left;
            }
        }
        return working_current;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
