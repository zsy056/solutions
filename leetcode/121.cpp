/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        if (prices.size() < 2) {
            return max_profit;
        }
        int hold = prices[0];
        for (int i=1; i<prices.size(); ++i) {
            auto profit = prices[i] - hold;
            max_profit = max(profit, max_profit);
            if (profit < 0) {
                hold = prices[i];
            }
        }
        return max_profit;
    }
};
