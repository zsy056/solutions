/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        sort(nums.begin(), nums.end());
        auto last = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            if (last == nums[i]) {
                return true;
            }
            last = nums[i];
        }
        return false;
    }
};
