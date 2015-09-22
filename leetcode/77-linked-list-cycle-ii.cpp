/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return combine(n, n, k);
    }

private:
    vector<vector<int>> combine(int n, int b, int k) {
        vector<vector<int>> result;
        for (int i = b; i>=k; --i) {
            auto prefixs = k > 1 ? combine(n, i-1, k-1) : vector<vector<int>>{vector<int>()};
            for (auto& prefix : prefixs) {
                prefix.push_back(i);
                result.push_back(move(prefix));
            }
        }
        return result;
    }
};
