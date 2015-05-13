/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxV(0);
        int a(0), b(height.size()-1);
        while (a < b) {
            int v((b-a) * min(height[a], height[b]));
            maxV = max(v, maxV);
            if (height[a] < height[b]) {
                int ha(height[a]);
                while (a < b && height[a] <= ha) {
                    ++a;
                }
            } else {
                int hb(height[b]);
                while (a < b && height[b] <= hb) {
                    --b;
                }
            }
        }
        return maxV;
    }
};
