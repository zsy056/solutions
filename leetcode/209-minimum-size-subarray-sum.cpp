/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_len = INT_MAX;
        int begin = 0;
        int end = 0;
        int current_sum = 0;
        while (end < nums.size()) {
            current_sum += nums[end];
            ++end;
            while (begin < end && current_sum - nums[begin] >= s) {
                current_sum -= nums[begin];
                ++begin;
            }
            if (current_sum >= s) {
                min_len = min(min_len, end - begin);
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
