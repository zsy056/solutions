/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return nums;
        }
        vector<int> result;
        deque<int> idxes;
        int i = 0;
        for (; i<k; ++i) {
            while (!idxes.empty() && nums[idxes.back()] < nums[i]) {
                idxes.pop_back();
            }
            idxes.push_back(i);
        }
        for (; i<nums.size(); ++i) {
            result.push_back(nums[idxes.front()]);

            while (!idxes.empty() && idxes.front() <= i - k) {
                idxes.pop_front();
            }

            while (!idxes.empty() && nums[idxes.back()] < nums[i]) {
                idxes.pop_back();
            }
            idxes.push_back(i);
        }
        result.push_back(nums[idxes.front()]);
        return result;
    }
};
