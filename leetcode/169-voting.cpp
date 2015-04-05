#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        auto current = num[0];
        auto counter = 1;
        for (auto i=1; i<num.size(); ++i) {
            if (counter == 0) {
                current = num[i];
                counter = 1;
            } else if (num[i] == current) {
                ++counter;
            } else {
                --counter;
            }
        }
        return current;
    }
};
