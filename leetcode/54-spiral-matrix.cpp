/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return vector<int>();
        }
        int x_bound_1 = -1;
        int x_bound_2 = matrix[0].size();
        int y_bound_1 = -1;
        int y_bound_2 = matrix.size();
        int state = 0;
        vector<int> ret;
        int i = 0;
        int j = 0;
        while ((x_bound_1 < x_bound_2 || y_bound_1 < y_bound_2)
                && i > y_bound_1 && i < y_bound_2
                && j > x_bound_1 && j < x_bound_2) {
            ret.push_back(matrix[i][j]);
            switch (state) {
            case 0:
                if (j + 1 < x_bound_2) {
                    ++j;
                } else {
                    ++i;
                    state = 1;
                    ++y_bound_1;
                }
                break;
            case 1:
                if (i + 1 < y_bound_2) {
                    ++i;
                } else {
                    --j;
                    state = 2;
                    --x_bound_2;
                }
                break;
            case 2:
                if (j - 1 > x_bound_1) {
                    --j;
                } else {
                    --i;
                    state = 3;
                    --y_bound_2;
                }
                break;
            case 3:
                if (i - 1 > y_bound_1) {
                     --i;
                } else {
                    ++j;
                    state = 0;
                    ++x_bound_1;
                }
                break;
            }
        }
        return ret;
    }
};
