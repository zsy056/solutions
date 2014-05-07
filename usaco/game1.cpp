/* 
ID: zsy
LANG: C++
PROG: game1 
*/
#include <iostream>
#include <fstream>
#include <algorithm>

#define PROG "game1"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define MAX_N 101

int opt[MAX_N][MAX_N] = { 0 };
int rsum[MAX_N][MAX_N] = { 0 };
int n;
int seq[MAX_N] = { 0 };

inline void fill_rsum()
{
    for (int i=1; i<n+1; ++i) {
        for (int j=i; j<n+1; ++j) {
            rsum[i][j] = rsum[i][j-1] + seq[j];
        }  
    }
}

int main()
{
    in >> n; 
    for (int i=1; i<n+1; ++i) {
        in >> seq[i]; 
    }
    for (int i=1; i<n+1; ++i) {
        opt[i][i] = seq[i];
    }
    fill_rsum();
    for (int r=1; r<n; ++r) {
        for (int i=1; i<n+1-r; ++i) {
            opt[i][i+r] = rsum[i][i+r] - min(opt[i][i+r-1], opt[i+1][i+r]);
        }
    }
    out << opt[1][n] << ' ' << rsum[1][n] - opt[1][n] << endl;
    return 0;
}
