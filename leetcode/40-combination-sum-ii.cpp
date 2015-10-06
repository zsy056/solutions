/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](int a, int b){ return a > b; });
        vector<int> compressed;
        vector<int> counts;
        if (candidates.size() > 0) {
            compressed.push_back(candidates[0]);
            counts.push_back(1);
        }
        for (int i=1; i<candidates.size(); ++i) {
            if (candidates[i] == compressed.back()) {
                ++(counts.back());
            } else {
                compressed.push_back(candidates[i]);
                counts.push_back(1);
            }
        }
        return combinationSum(compressed, counts, 0, target);
    }
private:
    vector<vector<int>> combinationSum(const vector<int> &compressed, const vector<int> &counts,
            int begin, int target) {
        vector<vector<int>> results;
        for (int i=begin; i<compressed.size(); ++i) {
            for (int j=1; j<=counts[i]; ++j) {
                if (target == compressed[i] * j) {
                    results.push_back(vector<int>(j, compressed[i]));
                } else if (target > compressed[i] * j) {
                    auto prefixes = combinationSum(compressed, counts, i+1, target - compressed[i]*j);
                    vector<int> postfix(j, compressed[i]);
                    for (auto &prefix : prefixes) {
                        prefix.insert(prefix.end(), postfix.begin(), postfix.end());
                        results.push_back(move(prefix));
                    }
                }
            }
        }
        return results;
    }
};
