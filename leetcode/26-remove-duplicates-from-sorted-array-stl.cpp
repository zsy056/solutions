class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int currentIdx(0), i(currentIdx+1);
        while (i < n) {
            auto it = upper_bound(A+i, A+n, A[currentIdx]);
            if (it >= A+n) {
                break;
            }
            A[++currentIdx] = *it;
            i = it - A + 1;
        }
        return n == 0 ? 0 : currentIdx + 1;
    }
};
