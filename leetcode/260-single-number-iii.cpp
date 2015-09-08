/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        auto xo = get_xo(nums, [] (int a) { return true; });
        auto pos = one_pos(xo);
        auto x = get_xo(nums, [pos, this] (int a) { return get(a, pos) == 1; });
        auto y = get_xo(nums, [pos, this] (int a) { return get(a, pos) == 0; });
        return vector<int> {x, y};
    }

private:
    int one_pos(int a) {
        for (int i=0; i<sizeof(a)*8; ++i) {
            if (get(a, i) == 1) {
                return i;
            }
        }
        return -1;
    }

    int get_xo(const vector<int> nums, function<bool(int)> pred) {
        int xo = 0, i = 0;
        while (i < nums.size()) {
            if (pred(nums[i])) {
                xo = nums[i];
                break;
            }
            ++i;
        }
        ++i;
        while (i < nums.size()) {
            if (pred(nums[i])) {
                xo ^= nums[i];
            }
            ++i;
        }
        return xo;
    }

    int get(int a, int pos) {
        return (a >> pos) & 1;
    }
};
