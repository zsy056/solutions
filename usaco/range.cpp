/* 
ID: zsy
LANG: C++
PROG: range 
*/
#include <iostream>
#include <fstream>

#define PROG "range"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define MAX_N 256

int n = 0;
char field[2][MAX_N][MAX_N];
int counters[MAX_N] = {0};

bool generate(int src, int sn, int dst, int dm)
{
    bool all_zero = true;
    for (int i=0; i<sn-1; ++i) {
        for (int j=0; j<sn-1; ++j) {
            all_zero = all_zero && (field[src][i][j] == 0);
            if (field[src][i][j] == 1 && field[src][i][j+1] == 1
                    && field[src][i+1][j] == 1 && field[src][i+1][j+1] == 1) {
                field[dst][i][j] = 1;
                ++counters[dm];
            } else {
                field[dst][i][j] = 0;
            }
        }
    }
    return all_zero;
}

int main()
{
    in >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            in >> field[0][i][j];
            field[0][i][j] -= '0';
        }
    }
    int dm = 2;
    int src = 0, dst = 1;
    while (!generate(src, n, dst, dm)) {
        src = 1 - src;
        dst = 1 - dst;
        ++dm;
        --n;
    }
    for (int i=2; i<dm && counters[i] != 0; ++i) {
        out << i << " " << counters[i] << endl;
    }
    return 0;
}
