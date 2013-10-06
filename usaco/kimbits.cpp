/* 
ID: zsy
LANG: C++
PROG: kimbits 
*/
#include <cstring>
#include <iostream>
#include <fstream>

#define PROG "kimbits"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

int main()
{
    int N, L;
    unsigned int l;
    in >> N >> L >> l;
    unsigned int table[32][32] = { 0 };
    for (int i=1; i<=L; ++i) {
        table[0][i] = 1;
    }
    for (int i=0; i<=N; ++i) {
        table[i][0] = 1;
    }
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=L; ++j) {
            table[i][j] = table[i-1][j] + table[i-1][j-1];
        }
    }
    char res[32] = { 0 };
    int tn = N, tl = L;
    for (int i=0; i<N; ++i) {
        if (l <= table[tn-1][tl])
            res[i] = '0';
        else {
            res[i] = '1';
            l = l - table[tn-1][tl];
            --tl;
        }
        --tn;
    }
    out << res << endl;
    return 0;
}
