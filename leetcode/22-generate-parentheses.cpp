/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return gen(n, n);
    }
private:
    // a <= b
    vector<string> gen(int a, int b) {
        if (a == 0) {
            string r;
            for (int i=0; i<b; ++i) {
                r.push_back(')');
            }
            return vector<string>{r};
        }
        vector<string> results;
        auto tail1 = gen(a-1, b);
        for (auto &s : tail1) {
            results.push_back("(" + s);
        }
        if (a == b) {
            return results;
        }
        auto tail2 = gen(a, b-1);
        for (auto &s : tail2) {
            results.push_back(")" + s);
        }
        return results;
    }
};
