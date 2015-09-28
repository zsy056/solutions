/*
Implement pow(x, n).
*/
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 0;
        switch (n) {
        case -1:
            ans = 1/x;
            break;
        case 0:
            ans = 1;
            break;
        case 1:
            ans = x;
            break;
        default:
            auto tmp = myPow(x, n>>1);
            ans = tmp * tmp;
            if ((n & 1) == 1) {
                ans = ans * x;
            }
            break;
        }
        return ans;
    }
};
