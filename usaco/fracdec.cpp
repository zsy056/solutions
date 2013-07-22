/*
ID: zsy
LANG: C++
PROG: fracdec
*/
#include <cstring>

#include <iostream>
#include <fstream>
#include <vector>

#define PROG "fracdec"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define OUTLEN 76
#define OUTBUFLEN 80

int a = 0, b = 0;
int c= 0;
int mod = 0;

int mods[100010];
vector<int> cs;
int idxbegin = -1;
char outbuf[OUTBUFLEN] = {0};

inline void output(const string& str)
{
    int stridx = 0;
    int size = str.size();
    while (stridx < size) {
        int i = 0;
        for (; i<OUTLEN && stridx < size; ++i) {
            outbuf[i] = str[stridx];
            ++ stridx;
        }
        outbuf[i] = '\0';
        out << outbuf << endl;
    }
}

int main()
{
    memset(mods, -1, sizeof(mods));
    in >> a >> b;
    c = a / b;
    mod = a % b;
    if (mod == 0) {
        cs.push_back(0);
    }
    while (mod != 0) {
        if (mods[mod] != -1) {
            int begin = mods[mod];
            for (int i=cs.size()-1; i>=0; --i) {
                if (cs[i] == begin) {
                    idxbegin = i;
                }
            }
            break;
        }
        int tc = mod * 10 / b;
        cs.push_back(tc);
        mods[mod] = tc;
        mod = mod * 10 % b;
    }
    sprintf(outbuf, "%d.", c);
    string outstr(outbuf);
    for (int i=0; i<cs.size(); ++i) {
        if (i == idxbegin) {
            outstr.push_back('(');
        }
        outstr.push_back('0' + cs[i]);
    }
    if (idxbegin != -1) {
        outstr.push_back(')');
    }
    output(outstr);
    return 0;
}
