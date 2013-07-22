/*
ID: zsy
LANG: C++
PROG: inflate
*/
#include <iostream>
#include <fstream>
#include <algorithm>

#define PROG "inflate"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define NMAX 10010

int m, n;
int score = 0;
struct Cls {
    int points;
    int min;
};

Cls clses[NMAX];
int res[NMAX] = {0};

int main()
{
    in >> m >> n;
    for (int i=0; i<n; ++i) {
        in >> clses[i].points >> clses[i].min;
    }
    for (int minu=1; minu<=m; ++minu) {
        for (int i=0; i<n; ++i) {
            if (minu >= clses[i].min
                    && res[minu] < res[minu-clses[i].min] + clses[i].points) {
                res[minu] = res[minu-clses[i].min] + clses[i].points;
            }
        }
    }
    out << res[m] << endl;
    return 0;
}
