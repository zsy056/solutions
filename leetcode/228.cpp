/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 0) {
            return result;
        }
        auto last_begin = nums[0];
        auto last_end = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            if (last_end + 1 != nums[i]) {
                stringstream ss;
                if (last_end == last_begin) {
                    ss << last_end;
                } else {
                    ss << last_begin << "->" << last_end;
                }
                result.push_back(ss.str());
                last_begin = nums[i];
                last_end = nums[i];
            }
            last_end = nums[i];
        }
        stringstream ss;
        if (last_end == last_begin) {
            ss << last_end;
        } else {
            ss << last_begin << "->" << last_end;
        }
        result.push_back(ss.str());

        return result;
    }
};
