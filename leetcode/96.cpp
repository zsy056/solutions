/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

class Solution {
public:
    int numTrees(int n) {
        if (n < record.size()) {
            return record[n];
        }
        for (auto i=record.size(); i<=n; ++i) {
            int tmp(0);
            for (auto j=0; j<=i/2-1; ++j) {
                tmp += record[j] * record[i-1-j];
            }
            tmp *= 2;
            if ((i & 1) == 1) {
                tmp += record[i/2] * record[i/2];
            }
            record.push_back(tmp);
        }
        return record[n];
    }

private:
    vector<int> record = {1, 1, 2};
};
