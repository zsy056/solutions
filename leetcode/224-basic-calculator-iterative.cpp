/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        auto stripped = strip(s);
        stack<string> stk;
        string tmp;
        for (auto c : stripped) {
            if (isdigit(c)) {
                tmp.push_back(c);
                continue;
            }
            if (!tmp.empty()) {
                stk.push(tmp);
                tmp.clear();
            }
            if (c == '(') {
                stk.push("(");
                continue;
            }
            if (c == '+' || c == '-') {
                stk.push(string(1, c));
                continue;
            }
            if (c == ')') {
                auto token = stk.top();
                int result = 0;
                int last = 0;
                stk.pop();
                while (token != "(") {
                    if (token == "-") {
                        result -= last;
                    } else if (token == "+") {
                        result += last;
                    } else {
                        last = stoi(token);
                    }
                    token = stk.top();
                    stk.pop();
                }
                result += last;
                stk.push(to_string(result));
            }
        }
        if (!tmp.empty()) {
            stk.push(tmp);
        }
        int result = 0;
        int last = 0;
        while (!stk.empty()) {
            auto token = stk.top();
            stk.pop();
            if (token == "-") {
                result -= last;
                continue;
            }
            if (token == "+") {
                result += last;
                continue;
            }
            last = stoi(token);
        }
        result += last;
        return result;
    }

    string strip(const string &s) {
        string tmp;
        for (auto c : s) {
            if (!isspace(c)) {
                tmp.push_back(c);
            }
        }
        return tmp;
    }

};

int main()
{
    Solution s;
    cout << s.calculate("2-(5-6)") << endl;
    return 0;
}
