#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Bucket {
    int min;
    int max;

    Bucket(): min(INT_MAX), max(INT_MIN) {}

    void add(int x) {
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
    }
};

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int min_num(INT_MAX), max_num(INT_MIN);
        for (auto i : nums) {
            if (i < min_num) {
                min_num = i;
            }
            if (i > max_num) {
                max_num = i;
            }
        }
        auto range = (max_num - min_num) / nums.size() + 1;
        vector<Bucket> buckets((max_num - min_num) / range + 1);
        for (auto i : nums) {
            auto a = i - min_num;
            buckets[a / range].add(i);
        }
        auto new_end = remove_if(buckets.begin(), buckets.end(),
                [](Bucket b){
                    return b.min == INT_MAX || b.max == INT_MIN;
                });
        int max_gap = INT_MIN;
        for (auto i=buckets.begin() + 1; i!=new_end; ++i) {
            if (i->min - (i-1)->max > max_gap) {
                max_gap = i->min - (i-1)->max;
            }
        }
        return max_gap;
    }
};

int main()
{
    Solution s;
    int raw[] = {1,1,1,1,1,2,2,2,2,2};
    vector<int> a(raw, raw + sizeof(raw) / sizeof(raw[0]));
    cout << s.maximumGap(a) << endl;
    return 0;
}
