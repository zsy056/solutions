/*
ID: zsy
LANG: C++
PROG: comehome
*/
#include <cctype>
#include <climits>

#include <iostream>
#include <fstream>

#define PROG "comehome"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define NMAX 256

int dist[NMAX][NMAX] = {0};
int p = 0;
int res[NMAX] = {0};

void dfs(char c, int depth)
{
    if (isupper(c)) {
        if (res[c] == 0 || res[c] > depth) {
            res[c] = depth;
        }
    } else {
        for (int i='A'; i<='z'; ++i) {
            if (dist[c][i] != 0 &&
                    (res[i]==0 || res[i] > depth + dist[c][i])) {
                res[i] = depth + dist[c][i];
                dfs(i, depth + dist[c][i]);
            }
        }
    }
}

int main()
{
    in >> p;

    for (int k=0; k<p; ++k) {
        char c1, c2;
        in >> c1 >> c2;
        int dtmp;
        in >> dtmp;
        if (dist[c1][c2] == 0 || dist[c1][c2] > dtmp) {
            dist[c1][c2] = dist[c2][c1] = dtmp;
        }
    }
    for (int i='A'; i<='z'; ++i) {
        if (dist['Z'][i] != 0) {
            dfs(i, dist['Z'][i]);
        }
    }
    int min_d = INT_MAX;
    char min_c = '?';
    for (int i='A'; i<'Z'; ++i) {
        if (res[i] != 0 && res[i] < min_d) {
            min_d = res[i];
            min_c = i;
        }
    }
    out << min_c << ' ' << min_d << endl;
    return 0;
}
