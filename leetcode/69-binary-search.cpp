/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int begin = 0;
        int end = x;

        while (begin < end) {
            int mid = (begin + end) / 2;
            mid = mid == 0 ? mid + 1 : mid;
            int rest = x / mid;
            if (rest > mid) {
                if (x / (mid + 1) < mid + 1) {
                    return mid;
                }
                begin = mid + 1;
            } else if (rest < mid) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return begin;
    }
};
