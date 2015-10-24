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

            vector<vector<int>> result;
            int size(uniqueNums.size());
            for (int i(0); i<size; ++i) {
                int a(uniqueNums[i]);
                --numCount[i];
                int start(numCount[i] == 0 ? i+1 : i), end(uniqueNums.size()-1);
                while (start < end || (start == end && numCount[start] >= 2)) {
                    int b(uniqueNums[start]), c(uniqueNums[end]);
                    if (a + b + c == 0) {
                        result.push_back(vector<int>({a, b, c}));
                        ++start;
                        --end;
                    } else if (a + b + c < 0) {
                        ++start;
                    } else {
                        --end;
                    }
                }
            }
            return result;
        }
};

int main()
{
    vector<int> nums({-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1});
    //vector<int> nums({0, 0, 0});
    Solution s;
    auto tuples(s.threeSum(nums));
    cout << tuples.size() << endl;
    for (auto &tuple : tuples) {
        cout << tuple[0] << ' ' << tuple[1] << ' ' << tuple[2] << endl;
    }
    return 0;
}
