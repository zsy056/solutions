/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp(n);
            result.push_back(move(tmp));
        }
        if (n == 0) {
            return result;
        }
        int x_bound_1 = -1;
        int x_bound_2 = n;
        int y_bound_1 = -1;
        int y_bound_2 = n;
        int state = 0;
        int i = 0;
        int j = 0;
        int now = 1;
        while ((x_bound_1 < x_bound_2 || y_bound_1 < y_bound_2)
                && i > y_bound_1 && i < y_bound_2
                && j > x_bound_1 && j < x_bound_2) {
            result[i][j] = now++;
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
        return result;
    }
};
