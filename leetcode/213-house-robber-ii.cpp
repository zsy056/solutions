/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }
        if (num.size() == 1) {
            return rob(num, 0, num.size());
        }
        auto rob_a = rob(num, 0, num.size()-1);
        auto rob_b = rob(num, 1, num.size());
        return max(rob_a, rob_b);
    }

private:
    int rob(const vector<int> &num, int a, int b) {
        vector<int> r_money(b - a, 0);
        vector<int> nr_money(b - a, 0);
        int max_rob = 0;
        for (auto i=0; i<b-a; ++i) {
            if (i == 0) {
                r_money[i] = num[i + a];
            } else if (i == 1) {
                r_money[i] = num[i + a];
                nr_money[i] = r_money[i-1];
            } else {
                r_money[i] = nr_money[i-1] + num[i + a];
                nr_money[i] = max(nr_money[i-1], r_money[i-1]);
            }
            max_rob = max(r_money[i], max(max_rob, nr_money[i]));
        }
        return max_rob;
    }
};
