/*
 * Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one(0), two(0), three(0);
        for (auto num : nums) {
            two |= num & one;
            one ^= num;
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one | two;
    }
};
