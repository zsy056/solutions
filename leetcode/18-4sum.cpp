/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> unique_nums;
        vector<int> counters;
        unique(nums, &unique_nums, &counters);
        vector<vector<int>> result;
        for (int i=0; i<unique_nums.size(); ++i) {
            int a = unique_nums[i];
            --counters[i];
            for (int j=(counters[i] > 0) ? i : i+1; j<unique_nums.size(); ++j) {
                int b = unique_nums[j];
                --counters[j];
                int idx_c = counters[j] > 0 ? j : j+1;
                int idx_d = unique_nums.size() - 1;
                while (idx_c < idx_d || (idx_c == idx_d && counters[idx_c] >= 2)) {
                    int c = unique_nums[idx_c];
                    int d = unique_nums[idx_d];
                    int sum = a + b + c + d;
                    if (sum == target) {
                        result.push_back(vector<int>{a, b, c, d});
                        --idx_d;
                        ++idx_c;
                    } else if (sum > target) {
                        --idx_d;
                    } else {
                        ++idx_c;
                    }
                }
                ++counters[j];
            }
            ++counters[i];
        }
        return result;
    }
private:
    void unique(const vector<int> &in, vector<int> *out, vector<int> *counters) {
        if (in.size() > 0) {
            out->push_back(in[0]);
            counters->push_back(1);
        }
        for (int i=1; i<in.size(); ++i) {
            if (in[i] == out->back()) {
                ++(counters->back());
            } else {
                out->push_back(in[i]);
                counters->push_back(1);
            }
        }
    }
};
