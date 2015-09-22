/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mtx(m + 1);
        for (int i=0; i<m+1; ++i) {
            vector<int> tmp(n + 1, INT_MAX);
            mtx[i] = move(tmp);
        }
        mtx[1][1] = grid[m-1][n-1];
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                }
                mtx[i][j] = grid[m-i][n-j] + min(mtx[i-1][j], mtx[i][j-1]);
            }
        }
        return mtx[m][n];
    }
};
