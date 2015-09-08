/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) {
            return 0;
        }
        int counter = 0;
        deque<int> q2;
        deque<int> q3;
        deque<int> q5;
        q2.push_back(1);
        while (true) {
            auto p2 = q2.empty() ? INT_MAX : q2.front();
            auto p3 = q3.empty() ? INT_MAX : q3.front();
            auto p5 = q5.empty() ? INT_MAX : q5.front();
            auto m = min(p2, min(p3, p5));
            ++counter;
            if (counter == n) {
                return m;
            }
            q2.push_back(m * 2);
            q3.push_back(m * 3);
            q5.push_back(m * 5);
            if (p2 == m) {
                q2.pop_front();
            }
            if (p3 == m) {
                q3.pop_front();
            }
            if (p5 == m) {
                q5.pop_front();
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.nthUglyNumber(117) << endl;
    return 0;
}
