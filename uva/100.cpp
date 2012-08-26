#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define NUM 1000000
#define UNKNOWN -1

using namespace std;

int tmax;
unsigned int a, b;
int tmpres[NUM+1];

int get_clen(unsigned int n)
{
    if (n<=NUM && tmpres[n]!=UNKNOWN) {
        return tmpres[n];
    }
    // odd
    int tmp;
    if (n%2 == 1) {
        tmp = 1 + get_clen(3*n + 1);
    } else {
        tmp = 1 + get_clen(n/2);
    }
    if (n <= NUM) {
        tmpres[n] = tmp;
    }
    return tmp;
}

inline void cal()
{
    for (unsigned int i=min(a, b); i<=max(a, b); ++i) {
        int len;
        if ((len=get_clen(i)) > tmax) {
            tmax = len;
        }
    }
}

int main()
{
    memset(tmpres, UNKNOWN, sizeof(tmpres));
    tmpres[1] = 1;
    while (scanf("%u %u", &a, &b) == 2) {
        tmax = 0;
        cal();
        printf("%u %u %d\n", a, b, tmax);
    }

    return 0;
}
