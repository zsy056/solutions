/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    const static int TYPE1 = 0;
    const static int TYPE2 = 1;

    string longestPalindrome(string s) {
        auto maxLen(0), current(0), idx(0), type(TYPE1);
        for (auto i(0); i < s.length(); ++i) {
            auto offset(1);
            while (i-offset+1 >= 0 && i + offset < s.length()
                    && s[i-offset+1] == s[i+offset]) {
                ++offset;
            }
            --offset;
            if (offset * 2 > maxLen) {
                maxLen = offset * 2;
                type = TYPE1;
                idx = i;
            }
            offset = 1;
            while (i - offset >= 0 && i + offset < s.length()
                    && s[i-offset] == s[i+offset]) {
                ++offset;
            }
            --offset;
            if (offset * 2 + 1 > maxLen) {
                maxLen = offset * 2 + 1;
                type = TYPE2;
                idx = i;
            }
        }
        auto offset(type == TYPE1 ? maxLen/2 - 1 : (maxLen-1) / 2);
        return s.substr(idx-offset, maxLen);
    }
};
