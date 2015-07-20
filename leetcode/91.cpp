/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        vector<int> result(s.length() + 2);
        result[0] = 1;
        result[1] = 1;
        for (int i=2; i<=s.length()+1; ++i) {
            if (i >= 3 && valid(s[i-3], s[i-2])) {
                if (s[i-2] == '0') {
                    result[i] = result[i-2];
                } else {
                    result[i] = result[i-2] + result[i-1];
                }
            } else if (s[i-2] >= '1' && s[i-2] <= '9') {
                result[i] = result[i-1];
            } else {
                return 0;
            }
        }
        return result[s.length()+1];
    }
private:
    bool valid(char a, char b) {
        return (a == '2' && b >= '0' && b <= '6')
            || (a == '1' && b >= '0' && b <= '9');
    }
};
