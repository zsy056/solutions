/*
 * Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result(0);
        for (auto i(31); i>=0; --i) {
            auto counter(0);
            for (auto num : nums) {
                if (((num >> i) & 1) == 1) {
                    ++counter;
                }
            }
            if (counter % 3 == 0) {
                result = result << 1;
            } else {
                result = (result << 1) | 1;
            }
        }
        return result;
    }
};
