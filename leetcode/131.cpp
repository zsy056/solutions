/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        int n = s.length();
        vector<set<vector<string>>> levels(n+1);
        vector<string> current;
        for (auto c : s) {
            current.push_back(string(1, c));
        }
        levels[n].insert(move(current));
        for (int i=n-1; i>=1; --i) {
            auto &level = levels[i+1];
            for (auto &partition : level) {
                int m = partition.size();
                for (int j=0; j<m-1; ++j) {
                    if (is_reverse(partition[j], partition[j+1])) {
                        auto merged = merge(partition, j, j+1);
                        levels[i].insert(move(merged));
                    }
                }
            }
            if (i+2 > n) {
                continue;
            }
            auto &level2 = levels[i+2];
            for (auto &partition : level2) {
                int m = partition.size();
                for (int j=0; j<m-2; ++j) {
                    if (is_reverse(partition[j+1], partition[j+1])
                            && is_reverse(partition[j], partition[j+2])) {
                        auto merged = merge(partition, j, j+2);
                        levels[i].insert(move(merged));
                    }
                }
            }
        }
        for (int i=n; i>=1; --i) {
            results.insert(
                    results.end(),
                    levels[i].begin(),
                    levels[i].end());
        }

        return results;
    }

    inline void out(const vector<string> &v) {
        for (auto &s : v) {
            cout << s << ' ';
        }
        cout << endl;
    }
private:
    inline vector<string> merge(const vector<string> &original, int begin, int end) {
        vector<string> result;
        for (int i=0; i<begin; ++i) {
            result.push_back(original[i]);
        }
        string s;
        for (int i=begin; i<=end; ++i) {
            s.append(original[i]);
        }
        result.push_back(move(s));
        for (int i=end+1; i<original.size(); ++i) {
            result.push_back(original[i]);
        }
        return result;
    }

    inline bool is_reverse(const string &a, const string &b) {
        if (a.length() != b.length()) {
            return false;
        }
        for (int i=0; i<a.length(); ++i) {
            if (a[i] != b[b.length()-1-i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s("seeslaveidemonstrateyetartsnomedievalsees");
    Solution sol;
    sol.partition(s);
    return 0;
}
