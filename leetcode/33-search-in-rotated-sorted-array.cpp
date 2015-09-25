/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size(), target);
    }
private:
    // [begin, end)
    int search(const vector<int>& nums, int begin, int end, int target) {
        if (end == begin) {
            return -1;
        }
        if (end - begin == 1) {
            return nums[begin] == target ? begin : -1;
        }
        if (nums[begin] < nums[end-1]) {
            // normal binary search
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                return search(nums, begin, mid, target);
            } else {
                return search(nums, mid+1, end, target);
            }
        } else if (target == nums[begin]) {
            return begin;
        } else {
            int mid = (begin + end) / 2;
            int left = search(nums, begin, mid, target);
            return left == -1 ? search(nums, mid, end, target) : left;
        }
    }
};
