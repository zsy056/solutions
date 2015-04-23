class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int c(m+n-1), i(m-1), j(n-1);
        while (c >= 0 && i>=0 && j>=0) {
            if (A[i] >= B[j]) {
                A[c] = A[i];
                --i;
            } else {
                A[c] = B[j];
                --j;
            }
            --c;
        }
        while (c>=0 && j>=0) {
            A[c--] = B[j--];
        }
    }
};
