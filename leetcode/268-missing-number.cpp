/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto min_num = INT_MAX, max_num = INT_MIN, sum = 0;
        for (auto num : nums) {
            min_num = min(min_num, num);
            max_num = max(max_num, num);
            sum += num;
        }
        if (min_num != 0) {
            return 0;
        }
        if (max_num != nums.size()) {
            return nums.size();
        }
        auto expected_sum = max_num * (nums.size() + 1) / 2;
        return expected_sum - sum;
    }
};
