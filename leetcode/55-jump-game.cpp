/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size() - 2;
        int state = 0;
        int last_zero = -1;
        while (i >= 0) {
            if (state == 0)  {
                if (nums[i] == 0) {
                    state = 1;
                    last_zero = i;
                }
            } else {
                if (nums[i] > last_zero - i) {
                    state = 0;
                    last_zero = -1;
                }
            }
            --i;
        }
        return state == 0;
    }
};
