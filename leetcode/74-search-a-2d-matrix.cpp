/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        if (rowEnd == -1) {
            return false;
        }
        while (rowBegin < rowEnd) {
            int mid = (rowBegin + rowEnd) / 2;
            if (matrix[mid][0] > target) {
                rowEnd = mid - 1;
            } else if (matrix[mid][0] < target) {
                if (mid < matrix.size()-1 && matrix[mid+1][0] > target) {
                    rowBegin = mid;
                    break;
                }
                rowBegin = mid + 1;
            } else {
                return true;
            }
        }
        return binary_search(matrix[rowBegin].begin(), matrix[rowBegin].end(), target);
    }
};
