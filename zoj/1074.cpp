#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

#define MAX_N 100

int n;
int in[MAX_N+1][MAX_N+1];
int ts[MAX_N+1][MAX_N+1];

inline int sum(int a, int b, int i, int j)
{
    return ts[i][j] - ts[a-1][j] - ts[i][b-1] + ts[a-1][b-1];
}

inline int fill(int i, int j)
{
    return ts[i][j] = ts[i-1][j] + ts[i][j-1] - ts[i-1][j-1] + in[i-1][j-1];
}

inline int max_sum()
{
    ts[1][1] = in[0][0];
    int max = INT_MIN;
    for(int a=1; a<n+1; ++a){
        for(int b=1; b<n+1; ++b){
            //printf("a: %d, b:%d\n", a, b);
            for(int i=a; i<n+1; ++i){
                for(int j=b; j<n+1; ++j){
                    int now;
                    if(a==1 && b==1){
                        now = fill(i, j);
                    } else {
                        now = sum(a, b, i, j);
                    }
                    //printf("%d ", now);
                    if(now > max) {
                        max = now;
                    }
                }
                //puts("");
            }
        }
    }
    return max;
}

int main()
{
    memset(ts, 0, sizeof(ts[0][0])*(MAX_N+1)*(MAX_N+1));
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", &(in[i][j]));
        }
    }
    printf("%d\n", max_sum());
    return 0;
}
