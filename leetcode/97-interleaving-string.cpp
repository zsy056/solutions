/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if (m == 0) {
            return s2 == s3;
        }
        if (n == 0) {
            return s1 == s3;
        }
        if (m + n != s3.length()) {
            return false;
        }
        vector<vector<bool>> mtx(m + 1, vector<bool>(n + 1, false));
        mtx[0][0] = true;
        for (int i=1; i<=m; ++i) {
            mtx[i][0] = s1[i-1] == s3[i-1] && mtx[i-1][0];
        }
        for (int j=1; j<=n; ++j) {
            mtx[0][j] = s2[j-1] == s3[j-1] && mtx[0][j-1];
        }
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                mtx[i][j] = (s2[j-1] == s3[i+j-1] && mtx[i][j-1])
                            || (s1[i-1] == s3[i+j-1] && mtx[i-1][j]);
            }
        }
        return mtx[m][n];
    }
};
