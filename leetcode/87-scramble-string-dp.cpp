/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

using three_vector = vector<vector<vector<bool>>>;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() == 0 && s2.length() == 0) {
            return true;
        }
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.length() == 1) {
            return s1[0] == s2[0];
        }

        three_vector results;
        for (int i=0; i<=s1.length(); ++i) {
            vector<vector<bool>> two_d;
            for (int j=0; j<s1.length(); ++j) {
                two_d.push_back(vector<bool>(s1.length(), false));
            }
            results.push_back(move(two_d));
        }

        for (int i=0; i<s1.length(); ++i) {
            for (int j=0; j<s1.length(); ++j) {
                results[1][i][j] = s1[i] == s2[j];
            }
        }

        for (int k=2; k<=s1.length(); ++k) {
            for (int i=0; i<s1.length(); ++i) {
                for (int j=0; j<s1.length(); ++j) {
                    for (int l=1; l<k && i+l<s1.length() && j+l<s1.length(); ++l) {
                        if ((results[l][i][j] && results[k-l][i+l][j+l])
                                || (results[l][i][j+k-l] && results[k-l][i+l][j])) {
                            results[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }

        return results[s1.length()][0][0];
    }
};
