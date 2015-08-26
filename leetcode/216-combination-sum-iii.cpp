/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> current;
        get_combinations(n, results, current, 0, 1, k);
        return results;
    }
private:
    void get_combinations(
            int n,
            vector<vector<int>> &results,
            vector<int> &current,
            int current_sum,
            int begin,
            int k) {
        if (current.size() == k) {
            if (current_sum == n) {
                results.push_back(current);
            }
            return;
        }
        for (int i=begin; i<=9; ++i) {
            current.push_back(i);
            get_combinations(n, results, current, current_sum + i, i+1, k);
            current.pop_back();
        }
    }
};
