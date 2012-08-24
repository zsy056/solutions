#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_IN 14
#define NUM 6

int n;
bool flag = false;

int in[MAX_IN];

int out[NUM];

inline bool next_com()
{
    int now_max = n - 1;
    int now;
    int i;
    for(i=NUM-1; i>=0; --i){
        if(out[i] == now_max){
            --now_max;
            continue;
        } else {
            now = ++out[i];
            break;
        }
    }
    if(i==-1) return false;
    for(i=i+1; i<NUM; ++i){
        out[i] = ++now;
    }
    return true;
}

int main()
{
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        if(flag) puts("");
        flag = true;
        for(int i=0; i<n; ++i) {
            scanf("%d", &(in[i]));
        }
        for(int i=0; i<NUM; ++i){
            out[i] = i;
        }
        while(true){
            printf("%d", in[out[0]]);
            for(int i=1; i<NUM; ++i){
                printf(" %d", in[out[i]]);
            }
            puts("");
            if(!next_com()) break;
        }
    }
    return 0;
}
