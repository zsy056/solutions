#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        nth_element(num.begin(), num.begin() + (num.size() >> 1), num.end());
        return num[num.size() >> 1];
    }
};
