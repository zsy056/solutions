/*
ID: zsy
LANG: C++
PROG: humble
*/
#include <cmath>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

#define PROG "humble"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define KMAX 110
#define NMAX 100010

int k = 0;
int n = 0;
int s[KMAX] = {0};
int counter = 0;
uint64_t tres[NMAX] = {0};
set<uint64_t> res;

int main()
{
    in >> k >> n;
    for (int i=0; i<k; ++i) {
        in >> s[i];
    }
    tres[0] = 1;
    for (; counter<=n; ++counter) {
        for (int j=0; j<k; ++j) {
            uint64_t tmp = tres[counter] * s[j];
            if (res.size() + counter <= n || tmp < *res.rbegin()) {
                res.insert(tmp);
            }
        }
        tres[counter+1] = *res.begin();
        res.erase(res.begin());
        while (res.size() + counter > n) {
            res.erase(--res.rbegin().base());
        }
    }
    out << tres[n] << endl;
    return 0;
}
