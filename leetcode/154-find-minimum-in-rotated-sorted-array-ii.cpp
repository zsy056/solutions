#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
    int findMin(const vector<int> &num, int first, int last) {
        while (last > 0 && num[first] == num[last]) {
            --last;
        }
        if (first == last) {
            return num[first];
        }
        if (first == last - 1) {
            return min(num[first], num[last]);
        }
        if (num[first] < num[last]) {
            return num[first];
        }
        auto mid = first + (last - first + 1) /2;
        if (num[first] > num[mid]) {
            return findMin(num, first, mid);
        } else {
            return findMin(num, mid, last);
        }
    }
};
