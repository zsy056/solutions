/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size(), target) != -1;
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
