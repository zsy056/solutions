#include <iostream>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        int original(x);
        int64_t reverse(0);
        while (x > 0) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return original >= 0 ? original == reverse : false;
    }
};
