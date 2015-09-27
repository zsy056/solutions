/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i=0; i<=nums.size(); ++i) {
            vector<bool> chosen(nums.size(), false);
            subsets(nums, chosen, 0, i, result);
        }
        return result;
    }

private:
    void subsets(
            const vector<int> &num,
            vector<bool> &chosen,
            int b,
            int n,
            vector<vector<int>> &out) {
        if (n == 0) {
            vector<int> tmp;
            for (int i=0; i<chosen.size(); ++i) {
                if (!chosen[i]) {
                    continue;
                }
                tmp.push_back(num[i]);
            }
            out.push_back(move(tmp));
        } else {
            for (int i=b; i<=num.size()-n; ++i) {
                if (i-1 >= 0 && num[i] == num[i-1] && !chosen[i-1]) {
                    continue;
                }
                chosen[i] = true;
                subsets(num, chosen, i+1, n-1, out);
                chosen[i] = false;
            }
        }
    }
};

