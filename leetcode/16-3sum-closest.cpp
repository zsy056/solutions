/*
   Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

   For example, given array S = {-1 2 1 -4}, and target = 1.

   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
   */

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            if (nums.size() < 3) {
                return 0;
            }

            sort(nums.begin(), nums.end());
            vector<int> uniqueNums;
            vector<int> numCount;
            uniqueNums.push_back(nums[0]);
            numCount.push_back(1);
            for (auto i(1); i<nums.size(); ++i) {
                if (nums[i] == uniqueNums.back()) {
                    ++(numCount.back());
                } else {
                    numCount.push_back(1);
                    uniqueNums.push_back(nums[i]);
                }
            }

            int closest(-1);
            int minDiff(INT_MAX);
            int size(uniqueNums.size());
            for (int i(0); i<size; ++i) {
                int a(uniqueNums[i]);
                --numCount[i];
                int start(numCount[i] == 0 ? i+1 : i), end(uniqueNums.size()-1);
                while (start < end || (start == end && numCount[start] >= 2)) {
                    int b(uniqueNums[start]), c(uniqueNums[end]);
                    int sum(a + b + c);
                    int difference(sum - target);
                    int absDiff(abs(difference));
                    if (minDiff > absDiff) {
                        closest = sum;
                        minDiff = absDiff;
                    }
                    if (difference == 0) {
                        return target;
                    } else if (difference < 0) {
                        ++start;
                    } else {
                        --end;
                    }
                }
            }
            return closest;
        }
};
