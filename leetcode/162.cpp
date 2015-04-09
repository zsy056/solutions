#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        auto peak = findPeak(num, 0, num.size()-1);
        if (peak == -1) {
            if (num.back() - num.front() > 0) {
                return num.size() - 1;
            } else {
                return 0;
            }
        } else {
            return peak;
        }
    }

    int findPeak(const vector<int> &num, int first, int last) {
        if (first >= last-1) {
            return -1;
        }
        auto mid = (last - first + 1) / 2 + first;
        auto pindex1 = findPeak(num, first, mid);
        if (pindex1 != -1) {
            return pindex1;
        }
        auto pindex2 = findPeak(num, mid, last);
        if (pindex2 != -1) {
            return pindex2;
        }
        auto delta1 = num[mid] - num[first];
        auto delta2 = num[last] - num[mid];
        if (delta1 > 0 && delta2 < 0) {
            return mid;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    //int raw[] = {-67,-60,78,31,-24,-78,-89,14,-18,39,-4,60,-33,77,48,22,88,-40,-83,25,-55,68,61,-72,-77,8,-11,90,-75,-86,-85,-66,-79,26,30,32,81,27,12,86,23,-41,20,-58,57,10,54,-27,-63,-94};
    int raw[] = {1, 2, 3};
    vector<int> a(raw, raw + sizeof(raw)/sizeof(raw[0]));
    cout << s.findPeakElement(a) << endl;
    return 0;
}
