/*
 * 5 cards, 36 points
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr double TARGET = 36;
constexpr int NUMS = 5;

const vector<char> ops {'+', '-', '*', '/'};

using sol_t = pair<double, string>;


vector<sol_t> get_result(
        const vector<int> &nums,
        int begin,
        int end) {
    int size = end - begin;
    if (size == 0) {
        return vector<sol_t> {};
    }
    if (size == 1) {
        return vector<sol_t> { {nums[begin], to_string(nums[begin])} };
    }
    vector<sol_t> results;
    for (int i=begin+1; i<end; ++i) {
        auto left_sols = get_result(nums, begin, i);
        auto right_sols = get_result(nums, i, end);
        for (auto left : left_sols) {
            for (auto right : right_sols) {
                for (auto op : ops) {
                    auto valid = true;
                    double result = 0;
                    string expr;
                    switch (op) {
                    case '+':
                        result = left.first + right.first;
                        expr = left.second + "+" + right.second;
                        break;
                    case '-':
                        result = left.first - right.first;
                        expr = left.second + "-" + right.second;
                        break;
                    case '*':
                        result = left.first * right.first;
                        expr = left.second + "*" + right.second;
                        break;
                    case '/':
                        if (right.first != 0) {
                            result = 1.0 * left.first / right.first;
                            expr = left.second + "/" + right.second;
                        } else {
                            valid = false;
                        }
                        break;
                    default:
                        break;
                    }
                    expr = "(" + expr + ")";
                    if (valid) {
                        results.push_back({result, expr});
                    }
                }
            }
        }
    }
    return results;
}


int main()
{
    vector<int> nums(NUMS);
    for (int i=0; i<nums.size(); ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<string> exprs;
    do {
        auto results = get_result(nums, 0, nums.size());
        for (auto result : results) {
            if (result.first == TARGET) {
                exprs.push_back(result.second);
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));
    if (exprs.empty()) {
        cout << "No Solution!" << endl;
    } else {
        for (auto expr : exprs) {
            cout << expr << endl;
        }
    }
    return 0;
}
