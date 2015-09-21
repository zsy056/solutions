/*
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n+1, true);
        is_prime[1] = false;

        for (int i=2; i*i <= n; ++i) {
            for (int j=i*i; j <= n; j+=i) {
                is_prime[j] = false;
            }
        }

        int counter = 0;
        for (int i=1; i<n; ++i) {
            if (is_prime[i]) {
                ++counter;
            }
        }
        return counter;
    }
};
