#include <cstdio>
#include <vector>

using namespace std;

int& access1(vector<vector<int>> &mtx, int i, int j) {
    return mtx[i][j];
}

int& access2(vector<vector<int>> &mtx, int i, int j) {
    return mtx[j][i];
}

void solve(vector<vector<int>> &mtx, char dir, int n)
{
    int step    = dir == 'l' || dir == 'u' ? 1 : -1;
    int start   = dir == 'l' || dir == 'u' ? 1 : n-2;
    int end     = dir == 'l' || dir == 'u' ? n : -1;
    auto access = dir == 'l' || dir == 'r' ? access1 : access2;
    for (int i = 0; i != n; ++i) {
        for (int j = start; j != end; j += step) {
            for (int k = j-step; k != start-2*step && access(mtx, i, k) == 0; k -= step) {
                access(mtx, i, k)      = access(mtx, i, k+step);
                access(mtx, i, k+step) = 0;
            }
        }
        for (int j = start; j != end; j += step) {
            if (access(mtx, i, j-step) == access(mtx, i, j)) {
                access(mtx, i, j-step) *= 2;
                access(mtx, i, j) = 0;
            }
        }
        for (int j = start; j != end; j += step) {
            for (int k = j-step; k != start-2*step && access(mtx, i, k) == 0; k -= step) {
                access(mtx, i, k)      = access(mtx, i, k+step);
                access(mtx, i, k+step) = 0;
            }
        }
    }
}


int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; ++i) {
        int n;
        char dir[16] = {0};
        scanf("%d %s", &n, dir);
        vector<vector<int>> mtx(n);
        for (int j=0; j<n; ++j) {
            mtx[j] = vector<int>(n);
            for (int k=0; k<n; ++k) {
                scanf("%d", &mtx[j][k]);
            }
        }
        solve(mtx, dir[0], n);
        printf("Case #%d:\n", i+1);
        for (int j=0; j<n; ++j) {
            for (int k=0; k<n-1; ++k) {
                printf("%d ", mtx[j][k]);
            }
            printf("%d\n", mtx[j][n-1]);
        }
    }

    return 0;
}
