/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = 0;
        for (int i=nums.size()-1; i>=0; --i) {
            for (int j=nums.size()-1; j>i; --j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    idx = i+1;
                    goto out;
                }
            }
        }
out:
        sort(nums.begin()+idx, nums.end());
    }
};
