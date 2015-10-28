/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] != INT_MAX) {
                auto num = nums[i];
                if (num-1 > nums.size()) {
                    break;
                }
                if (nums[num-1] != INT_MAX) {
                    swap(nums[i], nums[num-1]);
                } else {
                    break;
                }
                nums[num-1] = INT_MAX;
            }
        }
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != INT_MAX) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
