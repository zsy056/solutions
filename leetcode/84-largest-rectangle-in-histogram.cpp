/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

using item_t = tuple<int, int>; // height, width

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
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

