/* 
ID: zsy
LANG: C++
PROG: hamming
*/
#include <iostream>
#include <fstream>
#include <vector>

#define PROG "hamming"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
int n = 0;
int b = 0;
int d = 0;
vector<int> res;

inline int get_distance(int op1, int op2)
{
    int counter = 0;
    for (int i=0; i<=b; ++i) {
        if (((op1>>i)&1) != ((op2>>i)&1)) {
            ++counter;
        }
    }
    return counter;
}

inline bool is_valid(int num, int dis)
{
    for (vector<int>::iterator i=res.begin(); i!=res.end(); ++i) {
        if (get_distance(num, *i) < dis) {
            //cout << num << ' ' << *i << ' ' 
            //    << get_distance(num, *i) << endl;
            return false;
        }
    }
    return true;
}

inline void output(ostream& os)
{
    int counter = 0;
    int ln_cnter = 0;
    for (vector<int>::iterator i=res.begin();
        i!=res.end() && counter<n; ++i) {
        os << *i;
        ++counter;
        ++ln_cnter;
        if (ln_cnter == 10) {
            ln_cnter = 0;
            if (i+1 != res.end() && counter!=n) {
                os << endl;
            }
        } else if (i+1 != res.end() && counter!=n) {
            os << ' ';
        }
    }
    os << endl;
}

int main()
{
    fin >> n >> b >> d;
    res.push_back(0);
    for (int i=1; i<(1<<b); ++i) {
        if (is_valid(i, d)) {
            res.push_back(i);
        }
    }
    output(fout);
    return 0;
}
