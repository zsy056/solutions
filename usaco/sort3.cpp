/* 
ID: zsy
LANG: C++
PROG: sort3 
*/
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

#define PROG "sort3"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
int n = 0;
int in[1000];
int tmp[1000];
int res[4][4];
int cnt = 0;

int main()
{
    fin >> n;
    for (int i=0; i<n; ++i) {
        fin >> in[i];
    }
    memcpy(tmp, in, sizeof(in[0])*n);
    memset(res, 0, sizeof(res));
    sort(tmp, tmp+n);
    for (int i=0; i<n; ++i) {
        if (in[i] != tmp[i]) {
            ++res[tmp[i]][in[i]];
        }
    }
    for (int i=1; i<=3; ++i) {
        for (int j=i+1; j<=3; ++j) {
            int t = min(res[i][j], res[j][i]);
            cnt += t;
            res[i][j] -= t;
            res[j][i] -= t;
        }
    }
    cnt += (res[1][3]+res[1][2]) * 2;
    fout << cnt << endl;
    return 0;
}
