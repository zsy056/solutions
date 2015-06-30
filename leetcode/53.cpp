/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        assert(nums.size() != 0);
        int current_sum = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            current_sum += nums[i];
            current_sum = max(current_sum, nums[i]);
            max_sum = max(current_sum, max_sum);
        }
        return max_sum;
    }
};
