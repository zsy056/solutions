/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i=1; i<=nums.size(); ++i) {
            auto partial = subsets(nums, nums.size()-1, i);
            result.insert(
                    result.end(),
                    make_move_iterator(partial.begin()),
                    make_move_iterator(partial.end()));
        }
        result.push_back(vector<int>());
        return result;
    }

private:
    vector<vector<int>> subsets(const vector<int> &num, int b, int n) {
        vector<vector<int>> result;
        for (int i=b; i>=n-1; --i) {
            auto prefixes = n > 1 ? subsets(num, i-1, n-1) : vector<vector<int>>{vector<int>()};
            for (auto &prefix : prefixes) {
                prefix.push_back(num[i]);
                result.push_back(move(prefix));
            }
        }
        return result;
    }
};
