/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        return trap(height, 0, height.size());
    }
private:
    int trap(const vector<int> &height, int begin, int end) {
        if (end - begin < 3 || begin < 0 || end > height.size()) {
            return 0;
        }
        int max_i = max_idx(height, begin, end);
        int max_i0 = max_idx(height, begin, max_i);
        int max_i1 = max_idx(height, max_i+1, end);
        int trap0 = 0;
        int trap1 = 0;
        if (max_i0 != -1) {
            trap0 = (max_i-max_i0-1) * height[max_i0];
            for (int i=max_i0+1; i<max_i; ++i) {
                trap0 -= height[i];
            }
        }
        if (max_i1 != -1) {
            trap1 = (max_i1-max_i-1) * height[max_i1];
            for (int i=max_i+1; i<max_i1; ++i) {
                trap1 -= height[i];
            }
        }
        return trap(height, begin, max_i0+1) + trap(height, max_i1, end)
            + trap0 + trap1;
    }

    int max_idx(const vector<int> &height, int begin, int end) {
        int max_h = INT_MIN;
        int max_i = -1;
        for (int i=begin; i<end; ++i) {
            if (height[i] > max_h) {
                max_h = height[i];
                max_i = i;
            }
        }
        return max_i;
    }
};
