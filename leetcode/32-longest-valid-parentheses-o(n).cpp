/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int start = 0;
        stack<int> idxes;
        int max_len = 0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '(') {
                idxes.push(i);
                if (start == INT_MAX) {
                    start = i;
                }
            } else if (idxes.empty()) {
                // interrupt
                start = INT_MAX;
            } else {
                auto idx = idxes.top();
                idxes.pop();
                auto begin = idxes.empty() ? min(start, idx) : idxes.top()+1;
                max_len = max(max_len, i - begin + 1);
            }
        }
        return max_len;
    }
};
