/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        auto facts = fact(n);
        string candidates = "123456789";
        --k;
        for (int i=n; i>=1; --i) {
            int rest = k / facts[i-1];
            s.push_back(candidates[rest]);
            for (int j=rest+1; j<i; ++j) {
                candidates[j-1] = candidates[j];
            }
            k = k % facts[i-1];
        }
        return s;
    }

private:
    vector<int> fact(int n) {
        vector<int> result;
        result.push_back(1);
        result.push_back(1);
        for (int i=2; i <= n; ++i) {
            result.push_back(i * result.back());
        }
        return result;
    }
};
