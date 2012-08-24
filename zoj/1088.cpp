#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX 150

int bds[MAX];

inline int find(int n)
{
    int i = 2;
    for(; true; ++i){
        memset(bds, 0, sizeof(bds[0])*MAX);
        int tmp_counter = 0, tt_counter = 1, idx = 0;
        bool flag = true;
        bds[0] = 1;
        while(tt_counter < n-1){
            while(tmp_counter < i){
                //printf("%d\n", idx);
                idx = (idx + 1) % n;
                if(bds[idx] != 1){
                    ++tmp_counter;
                }
            }
            //printf("%d\n", idx);
            if(idx == 1){
                flag = false;
                break;
            }
            bds[idx] = 1;
            ++tt_counter;
            tmp_counter = 0;
        }
        //printf("%d\n", i);
        if(flag){
            break;
        }
    }
    return i;
}

int main()
{
    int n;
    while(true){
        scanf("%d", &n);
        if(n <= 0){
            break;
        }
        printf("%d\n", find(n));
    }

    return 0;
}
