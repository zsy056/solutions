/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permute(nums, 0);
    }
private:
    vector<vector<int>> permute(vector<int> &num, int begin) {
        if (begin == num.size()) {
            return vector<vector<int>>{vector<int>()};
        }
        vector<vector<int>> result;
        for (int i=begin; i<num.size(); ++i) {
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
