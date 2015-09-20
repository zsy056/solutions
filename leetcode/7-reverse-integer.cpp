class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        while (x != 0) {
            int mod = x % 10;
            if ((x > 0 && reversed > (INT_MAX - mod)/ 10)
                || (x < 0 && reversed < (INT_MIN - mod)/ 10)) {
                reversed = 0;
                break;
            }
            reversed = reversed * 10 + mod;
            x /= 10;
        }
        return reversed;
    }
};
