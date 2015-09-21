/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsert(nums, 0, nums.size(), target);
    }
private:
    int searchInsert(const vector<int>& nums, int begin, int end, int target) {
        if (end - begin < 1) {
            return begin;
        }
        if (end - begin == 1) {
            return nums[begin] >= target ? begin : begin + 1;
        }
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            return searchInsert(nums, begin, mid, target);
        } else {
            return searchInsert(nums, mid, end, target);
        }
    }
};
