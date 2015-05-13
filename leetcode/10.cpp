/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Token {
    char c;
    char mod;

    Token(char c, char mod = 0): c(c), mod(mod) {}
};

class Solution {
public:
    bool isMatch(string s, string p) {
        auto tokens(getTokens(p));
        return isMatch(s, 0, tokens, 0);
    }

    bool isMatch(const string &s, int sbegin,
            const vector<Token> &tokens, int tbegin) {
        if (tokens.size() == tbegin && s.length() == sbegin){
            return true;
        }
        if (s.length() == sbegin && getNextNonStarTokenIndex(tokens, tbegin) == tokens.size()) {
            return true;
        }
        if (s.length() == sbegin || tokens.size() == tbegin) {
            return false;
        }
        if (tokens.size() - tbegin == 1) {
            if (tokens[tbegin].c == '.' && (tokens[tbegin].mod == '*'
                        || s.length() - sbegin == 1)) {
                return true;
            }
            if (tokens[tbegin].mod != '*') {
                return s.length() - sbegin == 1 && tokens[tbegin].c == s[sbegin];
            }
            for (int i(sbegin); i < s.length(); ++i) {
                if (s[i] != tokens[tbegin].c) {
                    return false;
                }
            }
            return true;
        }
        if (tokens[tbegin].mod != '*') {
            return (tokens[tbegin].c == '.' || tokens[tbegin].c == s[sbegin])
                && isMatch(s, sbegin+1, tokens, tbegin+1);
        }
        for (int i(sbegin); i<s.length(); ++i) {
            auto canMatch(isMatch(s, i, tokens, tbegin+1));
            if (canMatch) {
                return true;
            }
            if (tokens[tbegin].c != '.' && tokens[tbegin].c != s[i]) {
                return false;
            }
        }
        return getNextNonStarTokenIndex(tokens, tbegin+1) == tokens.size();
    }

    int getNextNonStarTokenIndex(const vector<Token> &tokens, int begin) {
        int i(begin);
        for (; i<tokens.size(); ++i) {
            if (tokens[i].mod != '*') {
                return i;
            }
        }
        return i;
    }

    vector<Token> getTokens(const string &p) {
        vector<Token> tokens;

        for (int i(0); i<p.length(); ++i) {
            Token token(p[i]);
            if (i+1 < p.length() && p[i+1] == '*') {
                token.mod = p[i+1];
                ++i;
            }
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main()
{
    Solution s;
    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "aa"));
    assert(s.isMatch("aaa", "aa") == false);
    assert(s.isMatch("aa", "a*"));
    assert(s.isMatch("aa", ".*"));
    assert(s.isMatch("ab", ".*"));
    assert(s.isMatch("aab", "c*a*b"));
    assert(s.isMatch("abb", "a*bb"));
    assert(s.isMatch("ab", "a*bb") == false);
    return 0;
}
