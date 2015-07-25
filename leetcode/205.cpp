/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        return isIsomorphic_(s, t) && isIsomorphic_(t, s);
    }

private:

    bool isIsomorphic_(const string &s, const string &t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> mapping;
        for (int i=0; i<s.length(); ++i) {
            auto it = mapping.find(s[i]);
            if (it == mapping.end()) {
                mapping[s[i]] = t[i];
            } else if (it->second != t[i]) {
                return false;
            }
        }
        return true;
    }
};
