#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        vector<int> mods;
        vector<int> res;
        int64_t numer = numerator;
        int64_t denomin = denominator;
        int64_t sign = numer * denomin >= 0 ? 0 : 1;
        numer = abs(numer);
        denomin = abs(denomin);
        auto int_part = numer / denomin;
        auto rest_part = numer % denomin;
        int index = -1;
        if (rest_part != 0) {
            mods.push_back(rest_part);
        }
        while (rest_part != 0) {
            res.push_back(rest_part * 10 / denomin);
            auto new_restpart = rest_part * 10 % denomin;
            auto old_mod = find(mods.begin(), mods.end(), new_restpart);
            if (old_mod != mods.end()) {
                index = old_mod - mods.begin();
                break;
            }
            mods.push_back(new_restpart);
            rest_part = new_restpart;
        }
        stringstream ss;
        if (sign == 1) {
            ss << '-';
        }
        ss << int_part;
        if (!res.empty()) {
            ss << '.';
        }
        for (auto i=0; i<res.size(); ++i) {
            if (index == i) {
                ss << '(';
            }
            ss << res[i];
        }
        if (index != -1) {
            ss << ')';
        }
        return ss.str();
    }
};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(-2147483648, -1) << endl;
    return 0;
}
