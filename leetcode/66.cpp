#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> rresult;
        for (int i=digits.size()-1; i>=0; --i) {
            if (digits[i] == 9 && carry == 1) {
                rresult.push_back(0);
            } else {
                rresult.push_back(digits[i] + carry);
                carry = 0;
            }
        }
        if (carry == 1) {
            rresult.push_back(1);
        }
        reverse(rresult.begin(), rresult.end());
        return rresult;
    }
};
