/* 
ID: zsy
LANG: C++
PROG: numtri 
*/
#include <iostream>
#include <fstream>
#include <algorithm>

#define PROG "numtri"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int in[1000][1000];
int res[1000][1000];
int r;

int main()
{
    fin >> r;
    for (int i=0; i<r; ++i) {
        for (int j=0; j<=i; ++j) {
            fin >> in[i][j];
        }
    }
    res[0][0] = in[0][0];
    for (int i=1; i<r; ++i) {
        for (int j=0; j<=i; ++j) {
            if (j == 0) {
                res[i][j] = in[i][j] + res[i-1][j];
            } else if (j == i) {
                res[i][j] = in[i][j] + res[i-1][j-1];
            } else {
                res[i][j] = in[i][j] + max(res[i-1][j-1], res[i-1][j]);
            }
        }
    }
    fout << (int)*max_element(&res[r-1][0], &res[r-1][r]) << endl;
    return 0;
}
