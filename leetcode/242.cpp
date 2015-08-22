/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:

    bool isAnagram(string s, string t) {
        int a[MAX_SIZE] = { 0 };
        int b[MAX_SIZE] = { 0 };
        set(s, a);
        set(t, b);
        return is_same(a, b, MAX_SIZE);
    }

private:

    const static int MAX_SIZE = 26;

    void set(const string &s, int counters[]) {
        for (auto c : s) {
            ++counters[c - 'a'];
        }
    }

    bool is_same(int a[], int b[], int n) {
        for (int i=0; i<n; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};
