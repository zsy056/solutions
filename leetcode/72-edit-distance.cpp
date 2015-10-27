/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> mtx(m + 1);
        for (int i=0; i<m+1; ++i) {
            vector<int> tmp(n + 1, 0);
            mtx[i] = move(tmp);
        }
        for (int j=0; j<n+1; ++j) {
            mtx[0][j] = j;
        }
        for (int i=0; i<m+1; ++i) {
            mtx[i][0] = i;
        }

        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    mtx[i][j] = mtx[i-1][j-1];
                } else {
                    mtx[i][j] = min(mtx[i-1][j], min(mtx[i-1][j-1], mtx[i][j-1])) + 1;
                }
            }
        }

        return mtx[m][n];
    }
};
