/* 
ID: zsy
LANG: C++
PROG: pprime 
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>

#define PROG "pprime"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int a, b;

inline int getdigi(int num)
{
    int digi = 0;
    while (num > 0) {
        ++digi;
        num /= 10;
    }
    return digi;
}

inline int pow(int x, int y) 
{
    int z = 1;
    for (int i=0; i<y; ++i) {
        z *= x;
    }
    return z;
}

inline int expand(int x, bool flag)
{
    char tmp[256];
    char res[256];
    sprintf(tmp, "%d", x);
    int len = flag ? strlen(tmp) : strlen(tmp) - 1;
    reverse_copy(tmp, tmp+len, res);
    res[len] = '\0';
    strcat(tmp, res);
    return atoi(tmp);
}

inline bool isprime(int x)
{
    int sx = (int)sqrt(x);
    for (int i=2; i<=sx; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    fin >> a >> b;
    int ad = getdigi(a);
    int bd = getdigi(b);
    for (int i=ad; i<=bd; ++i) {
        int j = (i-1)/2;
        for (int s=pow(10, j); s<pow(10, j+1); ++s) {
            int tmp = expand(s, i%2==0);
            if (tmp < a) continue;
            if (tmp > b)
                exit(EXIT_SUCCESS);
            if (isprime(tmp)) {
                fout << tmp << endl;
            }
        }
    }
    return 0;
}
