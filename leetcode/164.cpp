#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <memory>

using namespace std;


class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        auto smaller = shared_ptr<list<int> >(new list<int>());
        auto larger = shared_ptr<list<int> >(new list<int>());
        auto total = shared_ptr<list<int> >(new list<int>(nums.begin(), nums.end()));
        for (auto i=0; i<31; ++i) {
            for (auto j=total->begin(); j != total->end(); ++j) {
                if (((*j >> i) & 1) == 0) {
                    smaller->push_back(*j);
                } else {
                    larger->push_back(*j);
                }
            }
            smaller->splice(smaller->end(), *larger);
            swap(smaller, total);
            smaller->clear();
            larger->clear();
        }
        int max_gap = 0;
        for (auto i=total->begin(); i!=total->end();) {
            auto a = *i;
            ++i;
            if (i == total->end()) {
                break;
            }
            auto b = *i;
            int gap = b - a;
            if (gap > max_gap) {
                max_gap = gap;
            }
        }
        return max_gap;
    }
};

int main()
{
    Solution s;
    int raw[] = {1,1,1,1,1,5,5,5,5,5};
    vector<int> a(raw, raw + sizeof(raw) / sizeof(raw[0]));
    cout << s.maximumGap(a) << endl;
    return 0;
}
