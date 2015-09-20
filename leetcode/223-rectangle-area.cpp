/*
ind the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int64_t x1 = max(A, E);
        int64_t y1 = max(B, F);
        int64_t x2 = min(C, G);
        int64_t y2 = min(D, H);

        int64_t tm = x2 - x1;
        int64_t tn = y2 - y1;
        int64_t m = max((int64_t)0, tm);
        int64_t n = max((int64_t)0, tn);
        return (C-A) * (D-B) - m * n + (G-E) * (H-F);
    }
};
