#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int rob(vector<int> &num) {
        vector<int> r_money(num.size(), 0);
        vector<int> nr_money(num.size(), 0);
        int max_rob = 0;
        for (auto i=0; i<num.size(); ++i) {
            if (i == 0) {
                r_money[i] = num[i];
            } else if (i == 1) {
                r_money[i] = num[i];
                nr_money[i] = r_money[i-1];
            } else {
                r_money[i] = nr_money[i-1] + num[i];
                nr_money[i] = max(nr_money[i-1], r_money[i-1]);
            }
            max_rob = max(r_money[i], max(max_rob, nr_money[i]));
        }
        return max_rob;
    }
};
