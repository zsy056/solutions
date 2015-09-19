class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (auto i=0; i<n; ++i) {
            A[m+i] = B[i];
        }
        sort(A, A+m+n);
    }
};
