#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 1) {
            return A[0];
        }
        int current_neg(0), current_pos(0), max(0);
        if (A[0] > 0) {
            max = A[0];
            current_pos = A[0];
        } else if (A[0] < 0) {
            current_neg = A[0];
        }
        for (auto i=1; i<n; ++i) {
            if (A[i] > 0) {
                current_neg = current_neg * A[i];
                if (current_pos == 0) {
                    current_pos = A[i];
                } else {
                    current_pos = current_pos * A[i];
                }
            } else if (A[i] < 0) {
                auto tmp_neg = current_neg;
                if (current_pos == 0) {
                    current_neg = A[i];
                } else {
                    current_neg = current_pos * A[i];
                }
                current_pos = tmp_neg * A[i];
            } else {
                current_neg = 0;
                current_pos = 0;
            }
            if (current_pos > max) {
                max = current_pos;
            }
        }
        return max;
    }
};

int main()
{
    int a[] = {2,-1,1,1};
    Solution s;
    cout << s.maxProduct(a, sizeof(a) / sizeof(a[0])) << endl;
    return 0;
}
