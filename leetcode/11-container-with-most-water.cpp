/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

struct Item {
    int idx;
    int height;
    Item(int idx = 0, int height = 0): idx(idx), height(height) {}
};

bool operator<(const Item &lv, const Item &rv) {
    return lv.height > rv.height;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        vector<Item> items(height.size());
        for (int i(0); i<height.size(); ++i) {
            items[i].idx = i;
            items[i].height = height[i];
        }
        sort(items.begin(), items.end());
        int a(min(items[0].idx, items[1].idx)),
            b(max(items[0].idx, items[1].idx));
        int maxV((b-a) * items[1].height);
        for (int i(2); i<items.size(); ++i) {
            if (a == 0 && b == items.size() - 1) {
                break;
            }
            if (items[i].idx > a && items[i].idx < b) {
                continue;
            }
            if (items[i].idx < a) {
                a = items[i].idx;
            }
            if (items[i].idx > b) {
                b = items[i].idx;
            }
            int v((b-a) * items[i].height);
            maxV = max(maxV, v);
        }
        return maxV;
    }
};
