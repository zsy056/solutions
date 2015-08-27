/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int64_t, int> counts;
        int begin = 0, next = 0, n = nums.size();
        while (next <= k && next < n) {
            auto target = nums[next];
            auto result = check(counts, target, t);
            if (result) {
                return true;
            }
            counts[target] = 1;
            ++next;
        }
        while (next < n) {
            auto to_remove = counts.find(nums[begin]);
            if (to_remove->second == 1) {
                counts.erase(to_remove);
            } else {
                --(to_remove->second);
            }
            auto target = nums[next];
            auto result = check(counts, target, t);
            if (result) {
                return true;
            }
            counts[target] = 1;
            ++begin;
            ++next;
        }
        return false;
    }

private:
    bool check(const map<int64_t, int> &counts, int64_t target, int t) {
        auto it_begin = counts.lower_bound(target - t);
        for (auto it = it_begin; it != counts.end() && it->first <= target + t; ++it) {
            auto num = it->first;
            if (abs(num - target) <= t) {
                return true;
            }
        }
        return false;
    }
};
