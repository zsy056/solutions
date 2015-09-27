/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> mtx(m + 1);
        for (int i=0; i<=obstacleGrid.size(); ++i) {
            vector<int> tmp(n + 1, 0);
            mtx[i] = move(tmp);
        }
        if (obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        mtx[1][1] = 1;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (obstacleGrid[m-i][n-j] == 1 || (i == 1 && j == 1)) {
                    continue;
                }
                mtx[i][j] = mtx[i-1][j] + mtx[i][j-1];
            }
        }
        return mtx[m][n];
    }
};
