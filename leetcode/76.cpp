/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, queue<int>> mappings;
        unordered_map<char, int> counters;
        unordered_set<char> lacked;
        for (auto c : t) {
            mappings.insert({c, queue<int>()});
            lacked.insert(c);
            auto it = counters.find(c);
            if (it == counters.end()) {
                counters.insert({c, 1});
            } else {
                ++(it->second);
            }
        }
        int begin = -1;
        int end = -1;
        int chosenBegin = 0;
        int chosenEnd = INT_MAX;
        queue<char> seq;
        for (int i=0; i<s.length(); ++i) {
            auto it = mappings.find(s[i]);
            if (it == mappings.end()) {
                continue;
            }
            end = i;
            seq.push(s[i]);
            it->second.push(i);
            if (it->second.size() == 1) {
                if (begin == -1) {
                    begin = i;
                }
            }
            if (!lacked.empty() && lacked.find(s[i]) != lacked.end()) {
                if (counters[s[i]] == it->second.size()) {
                    lacked.erase(s[i]);
                }
            }
            while (lacked.empty() && !seq.empty()) {
                auto front = seq.front();
                if (mappings[front].size() > counters[front]) {
                    mappings[front].pop();
                    seq.pop();
                    begin = mappings[seq.front()].front();
                } else {
                    break;
                }
            }

            if (lacked.empty() && (end - begin) < (chosenEnd - chosenBegin)) {
                chosenBegin = begin;
                chosenEnd = end;
            }
        }
        return lacked.empty() ? s.substr(chosenBegin, (chosenEnd - chosenBegin + 1)) : "";
    }
};
