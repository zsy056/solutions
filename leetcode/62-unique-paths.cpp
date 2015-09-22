/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    const static int MAX_N = 100;

    int uniquePaths(int m, int n) {
        vector<vector<int>> mtx(MAX_N + 1);
        for (int i=0; i<MAX_N+1; ++i) {
            vector<int> tmp(MAX_N+1, 0);
            mtx[i] = move(tmp);
        }
        mtx[1][1] = 1;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (i==1 && j==1)
                    continue;
                mtx[i][j] = mtx[i-1][j] + mtx[i][j-1];
            }
        }
        return mtx[m][n];
    }
};
