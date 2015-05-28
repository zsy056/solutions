/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = bound(nums, 0, nums.size(), target, true);
        int upper = bound(nums, 0, nums.size(), target, false);
        return vector<int>{lower, upper};
    }
private:
    int bound(const vector<int> &nums, int begin, int end, int target, bool lower) {
        if (end <= begin) {
            return -1;
        }
        if (end - begin == 1) {
            return nums[begin] == target ? begin : -1;
        }
        if (end - begin == 2) {
            int a = lower ? begin : begin + 1;
            int b = lower ? begin + 1 : begin;
            return nums[a] == target ? a : (
                    nums[b] == target ? b : -1);
        }
        int mid = (begin + end) / 2;
        if (target < nums[mid] || (lower && target == nums[mid])) {
            return bound(nums, begin, mid+1, target, lower);
        } else {
            return bound(nums, mid, end, target, lower);
        }
    }
};
