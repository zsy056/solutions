#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix(strs.empty() ? "" : strs[0]);
        for (auto i=1; i<strs.size(); ++i) {
            string common;
            for (auto j=0; j<prefix.length() && j<strs[i].length(); ++j) {
                if (prefix[j] == strs[i][j]) {
                    common.push_back(prefix[j]);
                } else {
                    break;
                }
            }
            prefix = move(common);
        }
        return prefix;
    }
};
