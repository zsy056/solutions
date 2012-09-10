/* 
ID: zsy
LANG: C++
PROG: subset 
*/
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>

#define PROG "subset"

#define NUM 40

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
int n;
long long res[NUM][(1+NUM)*NUM/2+1];

int main()
{
#ifdef TEST
    cin >> n;
#else
    fin >> n;
#endif
    int mid = (1+n)*n / 4;
    for (int i=1; i<=n; ++i) {
        res[i][1] = 1;
    }
    for (int i=2; i<=n; ++i) {
        for (int j=2; j<=(1+i)*i/2; ++j) {
            res[i][j] = res[i-1][j-i] + res[i-1][j];
#ifdef TEST
            cout << res[i][j] << ' ';
#endif
        }
        #ifdef TEST
        cout << endl;
#endif
    }
    fout << ((mid*4==(1+n)*n) ? res[n][mid] : 0) << endl;
    return 0;
}
