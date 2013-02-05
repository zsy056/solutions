/* 
ID: zsy
LANG: C++
PROG: money 
Run 8 TLE
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

#define PROG "money"

const int NUM_COINS = 30;

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int value[NUM_COINS];
long long res[10010];
int v;
int n;
int tmp_sum = 0;

int main()
{
    memset(res, 0, sizeof(res));
    fin >> v >> n;
    for (int i=0; i<v; ++i) {
         fin >> value[i];
    }
    sort(value, value+v);
    
    res[0] = 1;

    for (int i=0; i<v; ++i) {
        for (int j=1; j<=n; ++j) {
            if (j-value[i] >= 0) 
                res[j] += res[j-value[i]];
        }
    }

    fout << res[n] << endl;
    return 0;
}
