/*
ID: zsy
LANG: C++
PROG: agrinet
*/
#include <cstring>
#include <climits>

#include <iostream>
#include <fstream>

#define PROG "agrinet"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define NMAX 150

int n = 0;
int dist[NMAX][NMAX] = {0};
int in_cnt = 0;
int connected[NMAX];
int sum = 0;

inline void update(int oldc, int c)
{
    for (int i=0; i<n; ++i) {
        if (connected[i] == oldc) {
            connected[i] = c;
        }
    }
}

int main()
{
    in >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            in >> dist[i][j];
        }
    }
    for (int i=0; i<n; ++i) {
        connected[i] = i;
    }
    while (in_cnt < n-1) {
        int min_len = INT_MAX;
        int min_i = 0, min_j = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==j || connected[i] == connected[j])
                    continue;
                if (min_len > dist[i][j]) {
                    min_len = dist[i][j];
                    min_i = i;
                    min_j = j;
                }
            }
        }
        ++in_cnt;
        sum += dist[min_i][min_j];
        if (connected[min_i] < connected[min_j]) {
            update(connected[min_j], connected[min_i]);
        } else {
            update(connected[min_i], connected[min_j]);
        }
    }
    out << sum << endl;
    return 0;
}
