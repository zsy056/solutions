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
        vector<int> result;
        if (nums.empty()) {
            return result;
        }
        int n = nums.size();
        vector<int> r1(n, 1);
        vector<int> r2(n, 1);
        r1[0] = nums[0];
        r2[n-1] = nums[n-1];
        for (int i=1; i<n; ++i) {
            r1[i] = r1[i-1] * nums[i];
        }
        for (int i=n-2; i>=0; --i) {
            r2[i] = r2[i+1] * nums[i];
        }
        for (int i=0; i<n; ++i) {
            int a = 1, b = 1;
            if (i > 0) {
                a = r1[i-1];
            }
            if (i < n-1) {
                b = r2[i+1];
            }
            result.push_back(a * b);
        }
        return result;
    }
};
