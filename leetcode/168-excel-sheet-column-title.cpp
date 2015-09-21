#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n > 0) {
            int rem = n % 26;
            s.push_back(rem == 0 ? 'Z' : rem + 'A' - 1);
            n = n / 26;
            if (rem==0)
                --n;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
