/* 
ID: zsy
LANG: C++
PROG: stamps 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define PROG "stamps"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define LINE_LEN (1<<14)

struct Res {
    int value;
    int k;
    Res(): value(0), k(-1) {}
};

int n = 0;
int k = 0;
vector<int> values;
Res res[LINE_LEN];

bool com(int a, int b)
{
    return a > b;
}

int main()
{
    in >> k >> n;
    int tmp_val = 0;
    for (int i=0; i<n; ++i) {
        in >> tmp_val;
        values.push_back(tmp_val);
    }
    sort(values.begin(), values.end());
    int i = 0;
    res[0].k = 0;
    while (true) {
        if (res[i].k == -1) {
            out << res[i-1].value << endl;
            break;
        }
        if (res[i].k == -1 || res[i].k > k || res[i].value < res[i-1].value) {
            out << res[i-1].value << endl;
            break;
        }
        for (size_t j=0; j<values.size(); ++j) {
            int new_value = res[i].value + values[j];
            int new_idx = new_value & (~(0xFFFFFFFF<<14));
            if (res[new_idx].value < new_value) {
                res[new_idx].value = new_value;
                res[new_idx].k = res[i].k + 1;
            }
            int new_k = 1 + res[i].k;
            if (res[new_idx].k < 0 || res[new_idx].k > new_k) {
                res[new_idx].k = new_k;
            }
        }
        //out << res[i].value << ' ' << res[i].k << endl;
        ++i;
        i = i & (~(0xFFFFFFFF<<14));
    }
    return 0;
}
