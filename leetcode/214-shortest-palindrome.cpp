/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return s;
        }
        auto stuffed = stuff(s);
        int stuff_len = stuffed.length();
        vector<int> p(stuff_len, 0);
        for (int i=0, j=0, right=0; j<stuff_len; ++j) {
            p[j] = right > j ? min(p[2*i-j], right - j) : 0;
            while (j-p[j]-1 >= 0 && j+p[j]+1 < stuff_len && stuffed[j-p[j]-1] == stuffed[j+p[j]+1]) {
                ++p[j];
            }
            if (j + p[j] > right) {
                i = j;
                right = i + p[i];
            }
        }
        int max_len = 1;
        for (int i=stuff_len/2; i>=0; --i) {
            if (i-p[i] == 0) {
                max_len = p[i];
                break;
            }
        }
        string prefix = s.substr(max_len);
        reverse(prefix.begin(), prefix.end());
        prefix.append(s);
        return prefix;
    }

private:

    string stuff(const string &s) {
        string result(1+2*s.length(), '#');
        for (int i=0; i<s.length(); ++i) {
            result[i*2+1] = s[i];
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.shortestPalindrome("a") << endl;
    return 0;
}
