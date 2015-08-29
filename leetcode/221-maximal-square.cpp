/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> result(m);
        int max_len = 0;
        for (int i=0; i<m; ++i) {
            vector<int> tmp(n, 0);
            result[i] = move(tmp);
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == '1') {
                    result[i][j] = 1;
                    max_len = max(max_len, 1);
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (result[i][j] != 0) {
                    if (i + 1 < m && j + 1 < n && matrix[i+1][j+1] == '1') {
                        auto potential = result[i][j];
                        while (potential >= 1) {
                            auto valid = check(matrix, i+1, j+1, m, n, potential);
                            if (valid) {
                                result[i+1][j+1] = potential + 1;
                                max_len = max(max_len, result[i+1][j+1]);
                                break;
                            }
                            --potential;
                        }
                    }
                }
            }
        }
        return max_len * max_len;
    }

private:
    bool check(const vector<vector<char>> &mtx, int a, int b, int m, int n, int x) {
        for (int i = a - x; i >= 0 && i < a; ++i) {
            if (mtx[i][b] == '0') {
                return false;
            }
        }
        for (int j = b - x; j >= 0 && j < b; ++j) {
            if (mtx[a][j] == '0') {
                return false;
            }
        }
        return true;
    }
};
