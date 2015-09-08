/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

enum TokenType {
    Lit,
    Plus,
    Minus,
    Multiply
};

struct Token {
    TokenType type;
    int val;

    Token(): type(TokenType::Lit), val(0) {}
    explicit Token(int val): type(TokenType::Lit), val(val) {}
    explicit Token(TokenType type): type(type), val(0) {}
};

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        auto tokens = to_token(input);
        return get_result(tokens, 0, tokens.size());
    }

private:
    vector<int> get_result(const vector<Token> &tokens, int begin, int end) {
        if (end - begin == 1) {
            return vector<int> { tokens[begin].val };
        }
        vector<int> results;
        for (int i = begin; i < end; ++i) {
            if (tokens[i].type == TokenType::Lit) {
                continue;
            }
            auto lefts = get_result(tokens, begin, i);
            auto rights = get_result(tokens, i+1, end);
            for (auto left : lefts) {
                for (auto right : rights) {
                    auto result = get_result(tokens[i], left, right);
                    results.push_back(result);
                }
            }
        }
        return results;
    }

    int get_result(const Token &op, int left, int right) {
        int result = 0;
        switch (op.type) {
        case TokenType::Plus:
            result = left + right;
            break;
        case TokenType::Minus:
            result = left - right;
            break;
        case TokenType::Multiply:
            result = left * right;
            break;
        default:
            break;
        }
        return result;
    }

    vector<Token> to_token(const string &input) {
        vector<Token> result;
        string tmp;
        for (auto c : input) {
            if (isdigit(c)) {
                tmp.push_back(c);
                continue;
            }
            if (!tmp.empty()) {
                auto lit = stoi(tmp);
                tmp.clear();
                result.push_back(Token(lit));
            }
            Token token;
            switch (c) {
            case '-':
                token = Token(TokenType::Minus);
                break;
            case '+':
                token = Token(TokenType::Plus);
                break;
            case '*':
                token = Token(TokenType::Multiply);
                break;
            default:
                break;
            }
            result.push_back(token);
        }
        if (!tmp.empty()) {
            auto lit = stoi(tmp);
            result.push_back(Token(lit));
        }
        return result;
    }
};
