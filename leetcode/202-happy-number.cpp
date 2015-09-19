#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> unHappy;
        return isTrulyHappy(abs(n), unHappy);
    }
private:
    bool isTrulyHappy(int n, unordered_set<int> &unHappy) {
        int next(0), origin(n);
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            next += digit * digit;
        }
        if (next == 1) {
            return true;
        }
        if (unHappy.find(next) != unHappy.end()) {
            return false;
        }
        unHappy.insert(origin);
        return isTrulyHappy(next, unHappy);
    }
};
