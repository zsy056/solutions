/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int64_t total = 1;
        int num_zero = 0;
        for (auto i : nums) {
            if (i != 0) {
                total *= i;
            } else {
                ++num_zero;
            }
        }
        if (num_zero >= 2) {
            total = 0;
        }
        vector<int> result(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            if (num_zero == 0) {
                result[i] = total * pow(nums[i], -1);
            } else if (num_zero >= 2) {
                result[i] = 0;
            } else if (nums[i] == 0) {
                result[i] = total;
            }
        }
        return result;
    }
};
