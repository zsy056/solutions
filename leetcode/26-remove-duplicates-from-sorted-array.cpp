class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int currentIdx(0);
        for (auto i=currentIdx+1; i<n; ++i) {
            if (A[currentIdx] == A[i]) {
                continue;
            } else {
                A[++currentIdx] = A[i];
            }
        }
        return n == 0 ? 0 : currentIdx + 1;
    }
};
