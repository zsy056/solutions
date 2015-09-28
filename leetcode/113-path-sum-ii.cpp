/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> output;
        vector<int> path;
        pathSum(root, sum, path, output);
        return output;
    }

private:
    void pathSum(TreeNode *root, int sum, vector<int> &current, vector<vector<int>> &output) {
        if (root == nullptr) {
            return;
        }
        current.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {
            output.push_back(current);
        } else {
            pathSum(root->left, sum - root->val, current, output);
            pathSum(root->right, sum - root->val, current, output);
        }
        current.pop_back();
    }
};
