/* 
ID: zsy
LANG: C++
PROG: frac1 
*/
#include <iostream>
#include <fstream>
#include <set>

#define PROG "frac1"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
int n = 0;

// a/b
struct frac {
    int a;
    int b;
    frac(): a(0), b(1) {}
    frac(int a, int b): a(a), b(b) {}
    inline void print(ostream& os) const
    {
        os << a << '/' << b << endl;
    }
};

bool operator<(const frac& lv, const frac& rv)
{
    return ((float)lv.a)/lv.b < ((float)rv.a)/rv.b;
}

set<frac> res;

int main()
{
    fin >> n;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<=i; ++j) {
            res.insert(frac(j, i));
        }
    }
    for (set<frac>::iterator i=res.begin(); i!=res.end(); ++i) {
        i->print(fout);
    }
    return 0;
}
