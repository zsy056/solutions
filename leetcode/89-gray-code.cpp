/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result {0};
        int current = 0;
        for (int i=0; i<n; ++i) {
            current = current == 0 ? 1 : current << 1;
            int m = result.size();
            for (int j=m-1; j>=0; --j) {
                result.push_back(current | result[j]);
            }
        }
        return result;
    }
};
