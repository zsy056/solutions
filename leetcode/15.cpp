/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            if (nums.size() < 3) {
                return vector<vector<int>>();
            }
            sort(nums.begin(), nums.end(), [](int a, int b) {
                    return a > b;
                    });
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
            auto tuples(genTuple(uniqueNums, numCount, 0, 3, 0));
            sort(tuples.begin(), tuples.end());
            auto uniqueEnd(unique(tuples.begin(), tuples.end()));
            vector<vector<int>> result;
            for (auto i(tuples.begin()); i!=uniqueEnd; ++i) {
                result.push_back(move(*i));
            }
            return result;
        }

    private:
        vector<vector<int>> genTuple(const vector<int> &uniqueNums,
                const vector<int> &uniqueCount, int start, int length, int sum) {
            if (length == 0) {
                if (sum == 0) {
                    return vector<vector<int>>({vector<int>()});
                }
                return vector<vector<int>>();
            }
            if (length == 1) {
                auto exist(binary_search(uniqueNums.begin()+start, uniqueNums.end(),
                            -sum,
                            [](int a, int b){ return a > b; }));
                if (!exist) {
                    return vector<vector<int>>();
                } else {
                    return vector<vector<int>>({vector<int>({-sum})});
                }
            }
            vector<vector<int>> result;
            for (int i(start); i<uniqueNums.size(); ++i) {
                for (int j(1); j<=uniqueCount[i] && j<=length; ++j) {
                    auto combines(genTuple(uniqueNums, uniqueCount, i+1, length-j, sum + j*uniqueNums[i]));
                    for (auto &combine : combines) {
                        for (int k(0); k<j; ++k) {
                            combine.push_back(uniqueNums[i]);
                        }
                        result.push_back(move(combine));
                    }
                }
            }
            return result;
        }
};

int main()
{
    //vector<int> nums({-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1});
    vector<int> nums({0, 0, 0});
    Solution s;
    auto tuples(s.threeSum(nums));
    cout << tuples.size() << endl;
    for (auto &tuple : tuples) {
        cout << tuple[0] << ' ' << tuple[1] << ' ' << tuple[2] << endl;
    }
    return 0;
}
