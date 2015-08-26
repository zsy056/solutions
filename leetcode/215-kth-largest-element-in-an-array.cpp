/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k-1, 0, nums.size());
    }

private:
    int findKthLargest(vector<int> &nums, int k, int begin, int end) {
        if (end == begin + 1) {
            return nums[begin];
        }
        int last = nums[end-1];
        int i = begin, confirmed = begin;
        while (i <= end - 2) {
            if (nums[i] >= last) {
                swap(nums[i], nums[confirmed]);
                ++confirmed;
            }
            ++i;
        }
        swap(nums[confirmed], nums[end-1]);
        if (confirmed == k) {
            return last;
        }
        if (confirmed < k) {
            return findKthLargest(nums, k, confirmed + 1, end);
        }
        return findKthLargest(nums, k, begin, confirmed);
    }
};
