/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

40 ms
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> num;
        permute(result, nums, num, used);
        return result;
    }
private:
    void permute(vector<vector<int>> &result, const vector<int> nums, vector<int> &num, vector<bool> &used) {
        if (num.size() == nums.size()) {
            result.push_back(num);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (!used[i]) {
                if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                    continue;
                }
                used[i] = true;
                num.push_back(nums[i]);
                permute(result, nums, num, used);
                num.pop_back();
                used[i] = false;
            }
        }
    }
};

#ifdef DEBUG

int main()
{
    Solution s;
    vector<int> a{1, 1, 2, 2, 3, 4};
    auto ps = s.permuteUnique(a);
    for (auto &p : ps) {
        for (auto n : p) {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}

#endif
