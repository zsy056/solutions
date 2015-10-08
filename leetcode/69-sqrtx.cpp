/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/**
 * https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
 */
class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int bit = 1 << 30;

        while (bit > x) {
            bit = bit >> 2;
        }

        while (bit != 0) {
            if (x >= res + bit) {
                x -= res + bit;
                res = (res >> 1) + bit;
            } else {
                res = res >> 1;
            }
            bit = bit >> 2;
        }
        return res;
    }
};
