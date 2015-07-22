/*
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }
        vector<int> idxes(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            idxes[i] = i;
        }
        sort(idxes.begin(), idxes.end(), [&nums](int a, int b) {
                return nums[a] < nums[b];
                });
        int last = nums[idxes[0]];
        int last_idx = idxes[0];
        for (int i=1; i<idxes.size(); ++i) {
            if (last == nums[idxes[i]] && idxes[i] - last_idx <= k) {
                return true;
            }
            last = nums[idxes[i]];
            last_idx = idxes[i];
        }
        return false;
    }
};
