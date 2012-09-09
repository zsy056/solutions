/* 
ID: zsy
LANG: C++
PROG: preface 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define PROG "preface"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

#define NUM 7
int val[] =  { 1000, 500, 100, 50,  10,  5,   1 };
char sig[] = { 'M',  'D', 'C', 'L', 'X', 'V', 'I' };
int res[NUM];
int maxdigi = NUM;

inline string itorom(int input)
{
    string ret;
    for (int i=0; i<NUM && input>0; ++i) {
        int q = input / val[i];
        input -= q * val[i];
        for (int j=0; j<q; ++j) {
            ret.push_back(sig[i]);
        }

        int k = (i+2 < NUM) ? i+2 : i+1;
        for ( ; k>i; --k) {
            // Only allow 10^n to sub
            if ((k&1) != 0) 
                continue;
            int remain = input + val[k] - val[i];
#ifdef TEST
            cout << remain << endl;
#endif
            if (remain >= 0) {
                ret.push_back(sig[k]);
                ret.push_back(sig[i]);
                input = remain;
                break;
            }
        }
    }
    return ret;
}

inline void count_char(const string& src)
{
    for (int i=0; i<NUM; ++i) {
        int cnt = count(src.begin(), src.end(), sig[i]);
        if (cnt!=0 && i<maxdigi) {
            maxdigi = i;
        }
        res[i] += cnt;
    }
}

int main()
{
    int total;
    fin >> total;
    for (int i=1; i<=total; ++i) {
#ifdef TEST
        cout << itorom(i) << endl;
#endif
        count_char(itorom(i));
    }
    for (int i=NUM-1; i>=maxdigi; --i) {
        fout << sig[i] << ' ' << res[i] << endl;
    }
    return 0;
}
