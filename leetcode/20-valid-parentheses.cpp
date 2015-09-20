#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> map({{')', '('}, {']', '['}, {'}', '{'}});
        for (auto i=0; i<s.length(); ++i) {
            switch (s[i]) {
                case '(': case '{': case '[':
                    stk.push(s[i]);
                    break;
                default:
                    if (stk.empty()) {
                        return false;
                    }
                    if (stk.top() == map[s[i]]) {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return stk.empty();
    }
};
