/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int current = nums[0];
        int total_count = 1;
        int current_count = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (current == nums[i]) {
                if (current_count == 2) {
                    continue;
                } else {
                    ++current_count;
                    nums[total_count] = nums[i];
                    ++total_count;
                }
            } else {
                current_count = 1;
                current = nums[i];
                nums[total_count] = nums[i];
                ++total_count;
            }
        }
        return total_count;
    }
};
