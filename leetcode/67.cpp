/**
 * Given two binary strings, return their sum (also a binary string).

 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int i(a.length() - 1), j(b.length() - 1);
        string result;
        auto carry(0);
        while (i >= 0 && j >= 0) {
            auto x(a[i--] - '0'), y(b[j--] - '0');
            auto z(x + y + carry);
            if (z == 2) {
                carry = 1;
            } else if (z == 3) {
                carry = 1;
            } else {
                carry = 0;
            }
            result.push_back('0' + (z & 1));
        }
        while (i >= 0 || j >= 0) {
            auto x(0);
            if (i >= 0) {
                x = a[i--] - '0';
            } else {
                x = b[j--] - '0';
            }
            auto z(x + carry);
            carry = z == 2 ? 1 : 0;
            result.push_back('0' + (z & 1));
        }
        if (carry == 1) {
            result.push_back('1');
        }
        string reversed;
        auto begin(false);
        for (int k(result.length() - 1); k >= 0; --k) {
            if (!begin && result[k] == '0') {
                continue;
            }
            begin = true;
            reversed.push_back(result[k]);
        }
        return reversed.length() == 0 ? "0" : reversed;
    }
};
