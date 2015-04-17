#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int64_t result = 0;
        string striped;
        int spaceidx = 0;
        while (spaceidx < str.length() && str[spaceidx] == ' ') {
            ++spaceidx;
        }
        while (spaceidx < str.length()) {
            striped.push_back(str[spaceidx]);
            ++spaceidx;
        }
        bool neg = !striped.empty() && striped[0] == '-';
        bool pos = !striped.empty() && striped[0] == '+';
        for (auto i=neg || pos ? 1 : 0; i<striped.length(); ++i) {
            if (striped[i] < '0' || striped[i] > '9') {
                break;
            }
            result = result * 10 + striped[i] - '0';
            if (!neg && result > INT_MAX) {
                return INT_MAX;
            }
            if (neg && -result < INT_MIN) {
                return INT_MIN;
            }
        }
        return neg ? -result : result;
    }
};
