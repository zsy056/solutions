/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:

    string longestPalindrome(string s) {
        vector<int> plen(s.length()*2 + 1, -1);
        auto stuffed = stuff(s);
        int right = 0;
        int center = 0;
        int current = 0;
        int max = -1;
        int max_idx = -1;
        while (current < plen.size()) {
            int current_mirror = 2 * center - current;
            if (plen[current_mirror] == -1 || plen[current_mirror]+current >= right) {
                int i = plen[current_mirror] == -1 ? 0 : right - current;
                while (current+i+1 < plen.size()
                        && current-i-1 >= 0
                        && stuffed[current-i-1] == stuffed[current+i+1]) {
                    ++i;
                }
                plen[current] = i;
                if (current + plen[current] > right) {
                    center = current;
                    right = center + plen[current];
                }
            } else {
                plen[current] = plen[current_mirror];
            }
            if (plen[current] > max) {
                max = plen[current];
                max_idx = current;
            }
            ++current;
            if (current + max >= plen.size()) {
                break;
            }
        }
        string result;
        for(int i=max_idx-max; i<=max_idx+max; ++i) {
            if (stuffed[i] == 0) {
                continue;
            } else {
                result.push_back(stuffed[i]);
            }
        }
        return result;
    }

private:
    string stuff(const string& s) {
        string result(s.length() * 2 + 1, 0);
        for (int i=0; i<s.length(); ++i) {
            result[2*i] = 0;
            result[2*i+1] = s[i];
        }
        result[2*s.length()] = 0;
        return result;
    }
};
