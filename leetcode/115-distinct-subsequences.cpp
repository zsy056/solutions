/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        vector<int> counter(nt, 0);
        for (auto c : s) {
            for (int i=nt-1; i>=0; --i) {
                if (c == t[i]) {
                    counter[i] += i == 0 ? 1 : counter[i-1];
                }
            }
        }
        return counter[nt-1];
    }
};
