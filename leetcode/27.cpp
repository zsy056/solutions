class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int current(-1), next(0);
        while (next < n) {
            if (A[next] != elem) {
                A[++current] = A[next++];
            } else {
                ++next;
            }
        }
        return current == -1 ? 0 : current + 1;
    }
};
