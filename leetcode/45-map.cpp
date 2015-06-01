/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        map<int, int> bounds;
        int min_step = 0;
        for (int i=0; i<nums.size(); ++i) {
            int curr_step = get_step(bounds, min_step, i);
            min_step = curr_step;
            update_bound(bounds, curr_step+1, i+nums[i]);
        }
        return min_step;
    }
private:
    void update_bound(map<int, int> &bounds, int step, int bound) {
        auto it = bounds.find(step);
        if (it == bounds.end()) {
            bounds[step] = bound;
        } else {
            it->second = max(it->second, bound);
        }
    }

    int get_step(const map<int, int> &bounds, int min_step, int idx) {
        for (auto i=bounds.lower_bound(min_step); i!=bounds.end(); ++i) {
            if (idx <= i->second) {
                return i->first;
            }
        }
        return min_step;
    }
};

#ifdef DEBUG

int main()
{
    Solution s;
    vector<int> v{1, 2};
    cout << s.jump(v) << endl;
    return 0;
}

#endif
