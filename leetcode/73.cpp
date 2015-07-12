/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        vector<bool> rows(matrix.size(), false);
        vector<bool> cols(matrix[0].size(), false);

        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i=0; i<rows.size(); ++i) {
            if (rows[i]) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        for (int j=0; j<cols.size(); ++j) {
            if (cols[j]) {
                for (int i=0; i<matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
