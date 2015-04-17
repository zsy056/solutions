#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        stringstream ss;
        ss << ((x < 0) ? -x : x);
        auto str = ss.str();
        std::reverse(str.begin(), str.end());
        stringstream sout(str);
        long long out;
        sout >> out;
        if (out > INT_MAX || out < INT_MIN) {
            out = 0;
        }
        return (x < 0) ? -out : out;
    }
};
