/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> groups;
        for (int i=0; i<strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            groups[tmp].push_back(i);
        }
        vector<string> result;
        for(auto i=groups.begin(); i!=groups.end(); ++i) {
            if (i->second.size() > 1) {
                for (auto idx : i->second) {
                    result.push_back(strs[idx]);
                }
            }
        }
        return result;
    }
private:
    string reverse(const string &src) {
        string res;
        int slen = src.length();
        for (int i=slen-1; i>=0; --i) {
            res.push_back(src[i]);
        }
        return res;
    }

};

#ifdef DEBUG
int main()
{
    Solution s;
    vector<string> ins{"", ""};
    auto res = s.anagrams(ins);
    for (auto & s : res) {
        cout << s << endl;
    }
    return 0;
}
#endif
