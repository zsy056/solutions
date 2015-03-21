#include<cmath>

class Solution {
public:
    int trailingZeroes(int n) {
        int power = 1;
        int result = 0;
        while (true) {
            int now = pow(5, power);
            int a = n / now;
            if (a==0) {
                break;
            }
            result += a;
            ++power;
        }
        return result;
    }
};
