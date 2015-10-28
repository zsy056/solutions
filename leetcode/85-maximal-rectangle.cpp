/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/


using item_t = tuple<int, int>; // height, width

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max_size = 0;

        vector<vector<bool>> visited(matrix.size());
        for (int i=0; i<matrix.size(); ++i) {
            visited[i] = vector<bool>(matrix[i].size(), false);
        }
        for (int i=0; i<matrix.size(); ++i) {
            for (int j=0; j<matrix[i].size(); ++j) {
                if (matrix[i][j] != '1' || visited[i][j] == true) {
                    continue;
                }
                vector<int> rows;
                for (int m=i; m<matrix.size() && matrix[m][j] != '0'; ++m) {
                    int count = 0;
                    visited[m][j] = true;
                    for (int n=j; n<matrix[m].size(); ++n) {
                        if (matrix[m][n] == '0') {
                            break;
                        } else {
                            ++count;
                        }
                    }
                    rows.push_back(count);
                }
                max_size = max(max_size, largestRectangleArea(rows));
            }
        }
        return max_size;
    }

private:
    int largestRectangleArea(const vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int max_size = INT_MIN;

        stack<item_t> stk;
        stk.push(make_tuple(height[0], 1));

        for (int i=1; i<height.size(); ++i) {
            if (height[i] > get<0>(stk.top())) {
                stk.push(make_tuple(height[i], 1));
            } else {
                int width = 1;
                int min_height = INT_MAX;
                while (!stk.empty() && get<0>(stk.top()) >= height[i]) {
                    min_height = min(min_height, get<0>(stk.top()));
                    width += get<1>(stk.top());
                    max_size = max(max_size, min_height * (width - 1));
                    stk.pop();
                }
                stk.push(make_tuple(height[i], width));
            }
        }
        int min_height = INT_MAX;
        int width = 0;
        while (!stk.empty()) {
            width += get<1>(stk.top());
            min_height = min(min_height, get<0>(stk.top()));
            max_size = max(max_size, min_height * width);
            stk.pop();
        }
        return max_size;
    }

};

