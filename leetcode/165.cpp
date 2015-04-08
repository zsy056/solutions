#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        uint64_t a = 0;
        uint64_t b = 0;
        stringstream sv1(version1), sv2(version2);
        while (sv1 && sv2) {
            sv1 >> a;
            sv2 >> b;
            if (a > b) {
                return 1;
            } else if (a < b) {
                return -1;
            } else {
                char tmp;
                sv1 >> tmp;
                sv2 >> tmp;
            }
        }
        if (!sv1 && !sv2) {
            return 0;
        }
        if (sv1) {
            sv1 >> a;
            return a == 0 ? 0 : 1;
        }
        if (sv2) {
            sv2 >> b;
            return b == 0 ? 0 : -1;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    cout << s.compareVersion("01", "1") << endl;
    return 0;
}
