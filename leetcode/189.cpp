#include <algorithm>
#include <vector>

class Solution {
public:
    void rotate1(int nums[], int n, int k) {
        std::vector<int> new_a(n);
        for (auto i=0; i<n; ++i) {
            new_a[(i+k) % n] = nums[i];
        }
        std::copy_n(new_a.begin(), n, nums);
    }

    void rotate2(int nums[], int n, int k) {
        std::vector<int> new_a(n*2);
        std::copy_n(nums, n, new_a.begin());
        std::copy_n(nums, n, new_a.begin() + n);
        std::copy_n(new_a.begin()+(n-k%n), n, nums);
    }

    void rotate(int nums[], int n, int k) {
        auto tk = k % n;
        if (tk == 0)
            return;
        for (auto i=0; i<tk; ++i) {
            std::swap(nums[i], nums[n-tk+i]);
        }
        this->rotate(nums+tk, n-tk, tk);
    }
};
