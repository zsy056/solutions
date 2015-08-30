/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

enum TokenType {
    None,
    Plus,
    Minus,
    Mul,
    Div,
    Lit
};

struct Token {
    TokenType type;
    int val;

    Token(): type(TokenType::None), val(0) {}
    explicit Token(int val): type(TokenType::Lit), val(val) {}
    explicit Token(TokenType type): type(type), val(0) {}
};

class Solution {
public:
    int calculate(string s) {
        stack<Token> stk;
        s = strip(s);
        string tmp;
        for (auto c : s) {
            if (isdigit(c)) {
                tmp.push_back(c);
                continue;
            }
            if (!tmp.empty()) {
                auto v = stoi(tmp);
                push_lit(v, stk);
                tmp.clear();
            }
            Token to_push;
            switch (c) {
            case '+':
                to_push = Token(TokenType::Plus);
                break;
            case '-':
                to_push = Token(TokenType::Minus);
                break;
            case '*':
                to_push = Token(TokenType::Mul);
                break;
            case '/':
                to_push = Token(TokenType::Div);
                break;
            default:
                break;
            }
            stk.push(to_push);
        }
        if (!tmp.empty()) {
            auto v = stoi(tmp);
            push_lit(v, stk);
        }
        if (stk.empty()) {
            return 0;
        }
        stack<Token> stk2;
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            stk2.push(t);
        }
        auto result = stk2.top();
        stk2.pop();
        while (!stk2.empty()) {
            auto op = stk2.top();
            stk2.pop();
            auto v = stk2.top();
            stk2.pop();
            switch (op.type) {
            case TokenType::Plus:
                result = Token(result.val + v.val);
                break;
            case TokenType::Minus:
                result = Token(result.val - v.val);
                break;
            default:
                break;
            }
        }
        return result.val;
    }

    void push_lit(int v, stack<Token> &stk) {
        Token current_token(v);
        if (!stk.empty()) {
            auto prev = stk.top();
            if (prev.type == TokenType::Mul || prev.type == TokenType::Div) {
                current_token = collapse(stk, current_token);
            }
        }
        stk.push(current_token);
    }

    Token collapse(stack<Token> &stk, Token v2) {
        if (stk.size() < 2) {
            return v2;
        }
        auto op = stk.top();
        stk.pop();
        auto v1 = stk.top();
        stk.pop();
        Token token;
        switch (op.type) {
        case TokenType::Mul:
            token = Token(v1.val * v2.val);
            break;
        case TokenType::Div:
            token = Token(v1.val / v2.val);
            break;
        default:
            break;
        }
        return token;
    }

    string strip(const string &s) {
        string stripped;
        for (auto c : s) {
            if (!isspace(c)) {
                stripped.push_back(c);
            }
        }
        return stripped;
    }
};
