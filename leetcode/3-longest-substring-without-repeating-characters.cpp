/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> record;
        auto i(0), j(1), maxCounter(s.length() == 0 ? 0 : 1);
        if (s.length() > 0) {
            record.insert({s[0], 0});
        }
        while (j < s.length()) {
            auto it(record.find(s[j]));
            if (it == record.end()) {
                record.insert({s[j], j});
            } else if (it->second >= i) {
                i = it->second + 1;
                it->second = j;
            } else {
                it->second = j;
            }
            maxCounter = j-i+1 > maxCounter ? j-i+1 : maxCounter;
            ++j;
        }
        return maxCounter;
    }
};

