/* 
ID: zsy
LANG: C++
PROG: checker 
*/
#include <cmath>
#include <iostream>
#include <fstream>
#include <queue>

#define PROG "checker"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int row = 0;
int col = 0;
int dia1 = 0;
int dia2 = 0;
int res[13];

int n;
int cnt = 0;

inline bool t_diag(int x, int y)
{
    if ((((dia1 >> (x-y+n-1)) & 1)) == 1)
        return false;
    if (((dia2 >> (x+y)) & 1) == 1)
        return false;
    return true; 
}

inline void s_diag(int x, int y)
{
    dia1 |= 1 << (x-y+n-1); 
    dia2 |= 1 << (x+y);
}

void step(int row)
{
    //cout << row << endl;
    if (row >= n)
        return;
    for (int i=0; i<n; ++i) {
        if (((col>>i) & 1) != 1) {
            if (!t_diag(row, i))
                continue;
            int ocol = col;
            int odia1 = dia1;
            int odia2 = dia2;
            col |= 1<<i;
            res[row] = i;
            s_diag(row, i); 
            if (row < n-1) {
                step(row+1);
            } else if (row == n-1) {
                if (++cnt <= 3) {
                    fout << res[0]+1;
                    for (int j=1; j<n; ++j)
                        fout << ' ' << res[j]+1;
                    fout << endl;
                }
            }
            col = ocol;
            dia1 = odia1;
            dia2 = odia2;
        }
    }
}

int main()
{
    fin >> n;
    step(0);
    fout << cnt << endl;
    return 0;
}
