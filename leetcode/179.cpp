#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

struct Num {
    int num;
    int shift;
    Num(int n): num(n), shift(0) {
        int length = 1;
        while (true) {
            int q = n / 10;
            if (q == 0)
                break;
            ++length;
            n = q;
        }
        shift = pow(10, length);
    }
};

bool operator<(const Num &num1, const Num &num2) {
    uint64_t n1 = num2.shift * num1.num + num2.num;
    uint64_t n2 = num1.shift * num2.num + num1.num;
    return n1 > n2;
}

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<Num> covs;
        for (auto num : nums) {
            covs.push_back(Num(num));
        }
        sort(covs.begin(), covs.end());
        stringstream ss;
        for (const auto &cov : covs) {
            ss << cov.num;
        }
        auto result = ss.str();
        return (result[0] == '0') ? "0" : result;
    }
};
