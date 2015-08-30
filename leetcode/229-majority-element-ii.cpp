/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = 0, m2 = 0;
        int counter1 = 0, counter2 = 0;
        for (auto i : nums) {
            if (counter1 != 0 && m1 == i) {
                ++counter1;
            } else if (counter2 !=0 && m2 == i) {
                ++counter2;
            } else if (counter1 == 0) {
                counter1 = 1;
                m1 = i;
            } else if (counter2 == 0) {
                counter2 = 1;
                m2 = i;
            } else {
                --counter1;
                --counter2;
            }
        }
        counter1 = 0;
        counter2 = 0;
        for (auto i : nums) {
            if (i == m1) {
                ++counter1;
            } else if (i == m2) {
                ++counter2;
            }
        }
        vector<int> result;
        if (counter1 > nums.size() / 3) {
            result.push_back(m1);
        }
        if (counter2 > nums.size() / 3) {
            result.push_back(m2);
        }
        return result;
    }

};
