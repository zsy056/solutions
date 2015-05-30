/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](int a, int b){ return a > b; });
        return combinationSum(candidates, 0, target);
    }
private:
    vector<vector<int>> combinationSum(const vector<int>& candidates, int begin, int target) {
        vector<vector<int>> results;
        for (int i=begin; i<candidates.size(); ++i) {
            if (target == candidates[i]) {
                results.push_back(vector<int>{candidates[i]});
            } else if (target > candidates[i]) {
                auto prefixes = combinationSum(candidates, i, target-candidates[i]);
                for (auto &prefix : prefixes) {
                    prefix.push_back(candidates[i]);
                    results.push_back(move(prefix));
                }
            }
        }
        return results;
    }
};
