/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

class Solution {
public:
    int countDigitOne(int n) {
        int result = 0;
        while (n > 0) {
            auto level = find_level(n);
            if (level < 10) {
                result += 1;
                break;
            }
            auto div = n / level;
            auto remain = n % level;
            if (div < 2) {
                result += count(level) + 1 + remain;
            } else {
                result += level + div * count(level);
            }
            n = remain;
        }
        return result;
    }

private:
    //[0, n)
    int count(int64_t n) {
        int result = 0;
        int64_t c = 1;
        while (c * 10 <= n) {
            result = result * 10 + c;
            c *= 10;
        }
        return result;
    }

    int find_level(int64_t n) {
        int64_t result = 1;
        while (result * 10 <= n) {
            result *= 10;
        }
        return result;
    }
};
