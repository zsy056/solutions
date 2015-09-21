#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> purified;
        for (auto i=0; i<s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                purified.push_back(s[i] - 'A' + 'a');
            } else if ((s[i] >= 'a' && s[i] <= 'z')
                    || (s[i] >= '0' && s[i] <= '9')) {
                purified.push_back(s[i]);
            }
        }
        vector<char> reversed(purified);
        reverse(reversed.begin(), reversed.end());
        return reversed == purified;
    }
};
