/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idxes(nums.size());
        for (auto i(0); i<nums.size(); ++i) {
            idxes[i] = i;
        }
        sort(idxes.begin(), idxes.end(), [&nums] (int idxa, int idxb) { return nums[idxa] < nums[idxb]; });
        for (auto i(0); i < idxes.size(); ++i) {
            auto another(target - nums[idxes[i]]);
            auto idx(lower_bound(idxes.begin() + i + 1, idxes.end(), another, [&nums] (int idxa, int value) { return nums[idxa] < value; }));
            if (idx != idxes.end() && nums[*idx] == another) {
                return vector<int>({min(idxes[i]+1, (*idx) + 1), max(idxes[i]+1, (*idx) + 1)});
            }
        }
        return vector<int>();
    }
};
