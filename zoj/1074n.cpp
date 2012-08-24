#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

#define MAX_N 100

int n;
int in[MAX_N][MAX_N];

inline int max_sub_seq(int* seq, int n)
{
    int now = 0;
    int max = INT_MIN;
    for(int i=0; i<n; ++i){
        now += seq[i];
        if(now < 0) now = 0;
        if(now > max) max = now;
    }
    return max;
}

inline int max_sum()
{
    int tmp[MAX_N];
    int max = INT_MIN;
    for(int i=0; i<n; ++i){
        memset(tmp, 0, sizeof(tmp[0])*n);
        for(int j=i; j<n; ++j){
            for(int k=0; k<n; ++k){
                tmp[k] += in[j][k];
            }
            int now = max_sub_seq(tmp, n);
            if(now > max) max = now;
        }
    }
    return max;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", &(in[i][j]));
        }
    }
    printf("%d\n", max_sum());
    return 0;
}
