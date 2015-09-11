/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, INT_MAX);
        res[0] = 0;
        for (int i=1; i<=n; ++i) {
            auto s = static_cast<int>(sqrt(i));
            if (s * s == i) {
                res[i] = 1;
            } else {
                for (int j=s; j>=1; --j) {
                    res[i] = min(res[i], 1 + res[i - j*j]);
                }
            }
        }
        return res[n];
    }
};


int main()
{
    Solution s;
    cout << s.numSquares(11) << endl;
    return 0;
}
