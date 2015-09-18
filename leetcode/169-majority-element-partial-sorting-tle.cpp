#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename Iterator>
void my_nth_impl_random_it(Iterator first, Iterator nth, Iterator last) {
    auto n = nth - first;
    auto size = last - first;
    while (size > 1) {
        auto flag = *(last - 1);
        auto current_last = last - 1;
        auto i = 0;
        while (current_last > first+i) {
            if (*(first + i) > flag) {
                swap(*(first + i), *current_last);
                --current_last;
            } else {
                ++i;
            }
        }
        if (n <= i) {
            last = first + i;
        } else {
            first = first + i;
        }
        size = last - first;
        cout << size << endl;
        n = nth - first;
    }
}

template<typename Iterator>
void my_nth_impl(Iterator first, Iterator nth, Iterator last, random_access_iterator_tag) {
    my_nth_impl_random_it(first, nth, last);
}

template<typename Iterator>
void my_nth(Iterator begin, Iterator nth, Iterator end) {
    using IterCategory = typename iterator_traits<Iterator>::iterator_category;
    my_nth_impl(begin, nth, end, IterCategory());
}


class Solution {
public:
    int majorityElement(vector<int> &num) {
        my_nth(num.begin(), num.begin() + (num.size() >> 1), num.end());
        return num[num.size() >> 1];
    }
};

int main()
{
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    Solution s;
    cout << s.majorityElement(nums) << endl;
    return 0;
}
