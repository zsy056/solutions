/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

72 ms
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return permute(nums, 0);
    }
private:
    vector<vector<int>> permute(vector<int> &num, int begin) {
        if (begin == num.size()) {
            return vector<vector<int>>{vector<int>()};
        }
        vector<vector<int>> result;
        unordered_set<int> tried;
        for (int i=begin; i<num.size(); ++i) {
            if (tried.count(num[i]) != 0) {
                continue;
            } else {
                tried.insert(num[i]);
            }
            swap(num[begin], num[i]);
            auto prefixes = permute(num, begin+1);
            for (auto &prefix : prefixes) {
                prefix.push_back(num[begin]);
                result.push_back(move(prefix));
            }
            swap(num[begin], num[i]);
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
