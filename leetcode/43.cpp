/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        const string &a = num1.length() < num2.length() ? num1 : num2;
        const string &b = num1.length() < num2.length() ? num2 : num1;
        vector<string> to_add;
        for (int i=a.length()-1; i>=0; --i) {
            string tmp = multiply(b, a[i] - '0');
            for (int j=0; j<a.length()-1-i; ++j) {
                tmp.push_back('0');
            }
            cout << tmp << endl;
            to_add.push_back(move(tmp));
        }
        string result = to_add.size() > 0 ? to_add[0] : "0";
        for (int i=1; i<to_add.size(); ++i) {
            cout << result << endl;
            result = move(add(result, to_add[i]));
        }
        int non_zero = result.length() - 1;
        for (int i = 0; i<result.length(); ++i) {
            if (result[i] != '0') {
                non_zero = i;
                break;
            }
        }
        return result.substr(non_zero);
    }
private:
    string multiply(const string &num1, int num2) {
        int carry = 0;
        string result;
        int len = num1.length();
        for (int i=len-1; i>=0; --i) {
            int num = (num1[i] - '0') * num2 + carry;
            if (num >= 10) {
                carry = num / 10;
                num %= 10;
            } else {
                carry = 0;
            }
            result.push_back('0' + num);
        }
        while (carry > 0) {
            result.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(result);
        return result;
    }

    void reverse(string &str) {
        for (int i=0; i<str.length()/2; ++i) {
            swap(str[i], str[str.length()-1-i]);
        }
    }

    string add(const string &num1, const string &num2) {
        string result;
        int carry = 0;
        int i = 0;
        int len1 = num1.length();
        int len2 = num2.length();
        while (len1-1-i >=0 && len2-1-i >= 0) {
            int num = num1[len1-1-i] + num2[len2-1-i] - 2 * '0' + carry;
            if (num >= 10) {
                carry = num / 10;
                num %= 10;
            } else {
                carry = 0;
            }
            result.push_back(num + '0');
            ++i;
        }
        while (len1-1-i >= 0) {
            int num = num1[len1-1-i] - '0' + carry;
            if (num >= 10) {
                carry = num / 10;
                num %= 10;
            } else {
                carry = 0;
            }
            result.push_back(num + '0');
            ++i;
        }
        while (len2-1-i >= 0) {
            int num = num2[len2-1-i] - '0' + carry;
            if (num >= 10) {
                carry = num / 10;
                num %= 10;
            } else {
                carry = 0;
            }
            result.push_back(num + '0');
            ++i;
        }
        while (carry > 0) {
            result.push_back('0' + carry % 10);
            carry /= 10;
        }
        reverse(result);
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("123", "456") << endl;
    return 0;
}
