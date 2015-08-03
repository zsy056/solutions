/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[i].size(); ++j) {
                if (grid[i][j] == '1' && flooding(grid, 0, i, j, false)) {
                    ++num;
                }
            }
        }
        return num;
    }

private:
    bool flooding(vector<vector<char>> &grid, char c, int i, int j, bool changed) {
        if (grid[i][j] != '1') {
            return changed;
        }
        grid[i][j] = c;
        if (i > 0) {
            flooding(grid, c, i-1, j, true);
        }
        if (i < grid.size()-1) {
            flooding(grid, c, i+1, j, true);
        }
        if (j > 0) {
            flooding(grid, c, i, j-1, true);
        }
        if (j < grid[i].size()-1) {
            flooding(grid, c, i, j+1, true);
        }
        return true;
    }
};
