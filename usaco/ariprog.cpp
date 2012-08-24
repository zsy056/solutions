/* 
ID: zsy
LANG: C++
PROG: ariprog
*/
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ofstream fout("ariprog.out");
ifstream fin("ariprog.in");
int n, m;

char v[125000];
int l[250*250];

int comp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void search()
{
    // find all bis
    int counter = 0;
    bool flag1 = true;
    for (int i=0; i<=m; ++i) {
        for (int j=i; j<=m; ++j) {
            int tmp = i*i + j*j;
            v[tmp] = 1;
            l[counter++] = tmp;
        }
    }
    sort(l, &l[counter]);
    int* end = unique(l, &l[counter]);
    counter = end-l;
    for (int b=1; b<=2*m*m/(n-1); ++b) {
        for (int i=0; i<counter && l[i]<=2*m*m-(n-1)*b; ++i) {
            int a = l[i];
            bool flag = true;
            for (int k=1; k<n; ++k) {
                int r = a + k*b;
                if (v[r] != 1) {
                    flag = false;
                    break;
                } 
            }
            if (flag) {
                flag1 = false;
                fout << a << ' ' << b << endl;
            }
        }
    }
    if (flag1)
        fout << "NONE" << endl;
}

int main()
{
    memset(v, 0, sizeof(v));
    fin >> n >> m;
    search();
    return 0;
}
