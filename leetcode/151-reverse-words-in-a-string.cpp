/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/

class Solution {
public:
    void reverseWords(string &s) {
        auto words = to_words(s);
        reverse(words.begin(), words.end());
        s = join(words, ' ');
    }

private:
    vector<string> to_words(const string &s) {
        vector<string> res;
        string tmp;
        for (auto c : s) {
            if (isspace(c)) {
                if (!tmp.empty()) {
                    res.push_back(move(tmp));
                }
            } else {
                tmp.push_back(c);
            }
        }
        if (!tmp.empty()) {
            res.push_back(move(tmp));
        }
        return res;
    }

    string join(const vector<string> &src, char sep) {
        string dst;
        if (src.empty()) {
            return dst;
        }
        dst = src[0];
        for (int i=1; i<src.size(); ++i) {
            dst.push_back(sep);
            dst.append(src[i]);
        }
        return dst;
    }
};
