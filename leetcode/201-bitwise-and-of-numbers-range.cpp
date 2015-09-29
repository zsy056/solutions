/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = m;
        for (int i=0; i < 32; ++i) {
            auto x = n & (0xFFFFFFFF ^ (1 << i));
            if (x >= m && x <=n) {
                result &= x;
            }
        }
        return result;
    }
};
