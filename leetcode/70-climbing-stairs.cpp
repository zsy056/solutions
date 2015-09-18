/**
 * You are climbing a stair case. It takes n steps to reach to the top.

 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n < results.size()) {
            return results[n];
        }
        for (auto i(results.size()); i<=n; ++i) {
            results.push_back(results[i-1] + results[i-2]);
        }
        return results[n];
    }
private:
    vector<int> results {0, 1, 2};
};
