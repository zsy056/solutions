/* 
ID: zsy
LANG: C++
PROG: nocows
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>

#define PROG "nocows"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
int n;
int k;
int res[205][105];

int main()
{
    fin >> n >> k;
    memset(res, 0, sizeof(res));
    for (int i=1; i<=k; ++i) {
        res[1][i] = 1;
    }
    for (int i=2; i<=k; ++i) {
        for (int j=1; j<=n; j+=2) {
            for (int m=1; m<=j-2; ++m) {
                res[j][i] += res[m][i-1] * res[j-1-m][i-1];
            }
            res[j][i] %= 9901;
        }
    }
    fout << (9901+res[n][k]-res[n][k-1])%9901 << endl;
    return 0;
}
