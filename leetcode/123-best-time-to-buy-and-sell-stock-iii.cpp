/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

using sol_t = tuple<int, int, int>;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> states { {INT_MIN, 0}, {0, 0}, {INT_MIN, 0}, {0, 0}};
        int current = 0, next = 1;
        for (auto price : prices) {
            states[0][next] = max(states[0][current], -price);
            states[1][next] = max(states[1][current], states[0][current] + price);
            states[2][next] = max(states[2][current], states[1][current] - price);
            states[3][next] = max(states[3][current], states[2][current] + price);
            swap(current, next);
        }
        return max(states[1][current], states[3][current]);
    }
};
