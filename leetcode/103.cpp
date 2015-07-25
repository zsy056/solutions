/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

using qitem_t = tuple<TreeNode*, int>;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<qitem_t> q;
        q.push(make_tuple(root, 0));
        vector<vector<int>> result;
        vector<int> current;
        int current_level = 0;

        while (!q.empty()) {
            auto item = q.front();
            auto node = get<0>(item);
            auto level = get<1>(item);
            q.pop();
            if (node == nullptr) {
                continue;
            }
            if (level != current_level) {
                if (current_level % 2 != 0) {
                    reverse(current.begin(), current.end());
                }
                result.push_back(move(current));
                current_level = level;
            }
            current.push_back(node->val);
            if (node->left != nullptr) {
                q.push(make_tuple(node->left, current_level+1));
            }
            if (node->right != nullptr) {
                q.push(make_tuple(node->right, current_level+1));
            }
        }
        if (!current.empty()) {
            if (current_level % 2 != 0) {
                reverse(current.begin(), current.end());
            }
            result.push_back(move(current));
        }

        return result;
    }
};
