/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
Credits:
Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.
*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        mappings = {{0,0}};
        for (const auto& b : buildings) {
            insert(b);
        }
        purify();
        auto first = mappings.begin();
        if (first != mappings.end() && first->first == 0 && first->second == 0) {
            mappings.erase(first);
        }
        vector<pair<int, int>> skyline;
        for (auto p : mappings) {
            skyline.push_back(p);
        }
        return skyline;
    }

private:
    map<int, int> mappings;

    // rect[0]: x
    // rect[1]: x + w
    // rect[2]: h
    void insert(const vector<int> &rect) {
        auto last_h = 0;
        auto lower_bound = mappings.lower_bound(rect[0]);
        if (lower_bound != mappings.end() && lower_bound != mappings.begin()) {
            --lower_bound;
            last_h = lower_bound->second;
        }
        auto it = mappings.lower_bound(rect[0]);
        if (it == mappings.end()) {
            mappings[rect[0]] = rect[2];
            mappings[rect[1]] = last_h;
            return;
        }

        if (it != mappings.end() && it->first > rect[0] && last_h < rect[2]) {
            mappings[rect[0]] = rect[2];
        }
        while (it != mappings.end() && it->first < rect[1]) {
            last_h = it->second;
            if (it->second < rect[2]) {
                mappings[it->first] = rect[2];
            }
            ++it;
        }
        if (mappings.find(rect[1]) == mappings.end()) {
            mappings[rect[1]] = last_h;
        }
    }

    // Remove unnecessary points.
    void purify() {
        if (mappings.size() <= 1) {
            return;
        }
        vector<int> to_remove;
        auto j = mappings.begin();
        auto i = j++;
        while (j != mappings.end() && i != mappings.end()) {
            if (i->second == j->second) {
                to_remove.push_back(j->first);
            }
            ++i;
            ++j;
        }
        for (auto k : to_remove) {
            mappings.erase(k);
        }
    }
};

