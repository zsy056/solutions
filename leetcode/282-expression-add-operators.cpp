/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add operators +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        get_results(num, 0, "", result, target, 0, 0);
        return result;
    }
private:
    void get_results(
            const string &num,
            int start,
            const string &current,
            vector<string> &result,
            int target,
            int64_t val,
            int64_t last) {
        if (start >= num.length()) {
            if (!current.empty() && val == target) {
                result.push_back(current);
            }
            return;
        }
        string current_num_s = string(1, num[start]);
        for (int i=start+1; i<=num.length(); ++i) {
            if (current_num_s.length() > 1 && current_num_s[0] == '0') {
                return;
            }
            auto current_num = stoll(current_num_s);
            if (current.empty()) {
                get_results(num, i, current_num_s, result, target, current_num, current_num);
            } else {
                get_results(num, i, current + "+" + current_num_s, result, target, val + current_num, current_num);
                get_results(num, i, current + "-" + current_num_s, result, target, val - current_num, -current_num);
                get_results(num, i, current + "*" + current_num_s, result, target, val - last + last * current_num, last * current_num);
            }
            if (i != num.length()) {
                current_num_s.push_back(num[i]);
            }
        }
    }
};

