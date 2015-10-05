/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

52 ms
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
        vector<int> unique;
        vector<int> count;
        if (nums.size() > 0) {
            unique.push_back(nums[0]);
            count.push_back(1);
        }
        for (int i=1; i<nums.size(); ++i) {
            if (unique.back() == nums[i]) {
                ++(count.back());
            } else {
                unique.push_back(nums[i]);
                count.push_back(1);
            }
        }
        return permute(unique, count, nums.size(), 0);
    }
private:
    vector<vector<int>> permute(vector<int> &unique, vector<int> &count, int len, int begin) {
        if (len == 0) {
            return vector<vector<int>>{vector<int>()};
        }
        vector<vector<int>> result;
        for (int i=begin; i<unique.size(); ++i) {
            if (count[i] == 0) {
                continue;
            }
            swap(unique[begin], unique[i]);
            swap(count[begin], count[i]);
            --count[begin];
            auto prefixes = permute(unique, count, len - 1, begin);
            for (auto &prefix : prefixes) {
                prefix.push_back(unique[begin]);
                result.push_back(move(prefix));
            }
            ++count[begin];
            swap(unique[begin], unique[i]);
            swap(count[begin], count[i]);
        }
        return result;
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
