/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        int64_t result = 0;
        bool flag = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        int64_t ldividend = dividend < 0 ? -(int64_t) dividend : dividend;
        int64_t ldivisor = divisor < 0 ? -(int64_t) divisor : divisor;
        int msb = 0;
        for (int i=0; i<31; ++i) {
            if (((ldivisor >> i) & 1) == 1) {
                msb = i+1;
            }
        }
        //cout << ldividend << ' ' << ldivisor << ' ' << msb << endl;
        for (int i=32-msb; i>=0; --i) {
            auto tmp = ldividend - (ldivisor << i);
            if (tmp >= 0) {
                result |= ((int64_t)1) << i;
                ldividend = tmp;
            }
            if (tmp == 0) {
                break;
            }
        }
        if (flag) {
            if (result > INT_MAX) {
                return INT_MIN;
            }
            return - (int) result;
        } else if (result > INT_MAX || result < 0) {
            return INT_MAX;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.divide(-2147483648, -1) << endl;
    return 0;
}
