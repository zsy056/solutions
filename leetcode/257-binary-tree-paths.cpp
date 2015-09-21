/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> results;
        collect(root, s, results);
        return results;
    }

private:

    void collect(TreeNode *root, string s, vector<string> &results) {
        if (root == nullptr) {
            return;
        }
        stringstream ss;
        ss << root->val;
        s.append(ss.str());
        if (root->left != nullptr || root->right != nullptr) {
            s.append("->");
            collect(root->left, s, results);
            collect(root->right, s, results);
        } else {
            results.push_back(s);
        }
    }
};
