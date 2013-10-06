/* 
ID: zsy
LANG: C++
PROG: ratios 
*/
#include <iostream>
#include <fstream>

#define PROG "ratios"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

int get_rem(int b[3][3], int i, int j)
{
    int i1 = (i+1) % 3;
    int i2 = (i+2) % 3;
    int j1 = (j+1) % 3;
    int j2 = (j+2) % 3;
    return b[i1][j1] * b[i2][j2] - b[i1][j2] * b[i2][j1];
}

int get_v(int b[3][3])
{
    int v = 0;
    for (int i=0; i<3; ++i) {
        int tv = get_rem(b, 0, i);
        v += b[0][i] * tv;
    }
    return v;
}

void get_rev(int b[3][3], int rev[3][3])
{
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            rev[i][j] = get_rem(b, j, i);
        }
    }
}

int main()
{
    int a[3] = { 0 };
    in >> a[0] >> a[1] >> a[2];
    int b[3][3] = { 0 };
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            in >> b[i][j];
        }
    }
    int bv = get_v(b);
    int rev_b[3][3] = { 0 };
    get_rev(b, rev_b);
    int res[3] = { 0 };
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            res[i] += a[j] * rev_b[j][i];
        }
    }
    int n = 1; 
    for (; n<200; ++n) {
        float tmp[3];
        for (int j=0; j<3; ++j) {
            tmp[j] = res[j] * 1.0 * n / bv;
        }
        bool ok = true;
        for (int j=0; j<3; ++j) {
            if (tmp[j] - (int)tmp[j] > 0.0000001) {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    for (int i=0; i<3; ++i) {
        res[i] = res[i] * n / bv;
        if (res[i] < 0 || n == 200) {
            out << "NONE" << endl;
            return 0;
        }
    }
    for (int i=0; i<3; ++i) {
        out << res[i] << ' ';
    }
    out << n << endl;
    return 0;
}
