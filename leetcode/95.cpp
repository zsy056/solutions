/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nums(n);
        for (int i=0; i<n; ++i) {
            nums[i] = i + 1;
        }
        return generateTrees(nums, 0, n);
    }

private:
    vector<TreeNode*> generateTrees(const vector<int> &nums, int begin, int end) {
        if (end - begin == 0) {
            return vector<TreeNode*> { nullptr };
        }
        if (end - begin == 1) {
            return vector<TreeNode*> { new TreeNode(nums[begin]) };
        }
        vector<TreeNode*> results;
        for (int i=begin; i<end; ++i) {
            auto lefts = generateTrees(nums, begin, i);
            auto rights = generateTrees(nums, i+1, end);
            for (auto left : lefts) {
                for (auto right : rights) {
                    auto node = new TreeNode(nums[i]);
                    node->left = left;
                    node->right = right;
                    results.push_back(node);
                }
            }
        }
        return results;
    }
};
