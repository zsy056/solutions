/* 
ID: zsy
LANG: C++
PROG: zerosum 
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>

#define PROG "zerosum"

using namespace std;

const int OP_LEN = 20;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int n = 0;
char ops[OP_LEN];

inline bool isok(const char* ops)
{
    int i = 1;
    int tmp = 1;
    int sum = 0;
    int op = 1;
    while (++i <= n) {
        switch (ops[i-1]) {
        case ' ':
            tmp = tmp*10 + i;
            break;
        case '+':
            sum += op * tmp;
            tmp = i;
            op = 1;
            break;
        case '-':
            sum += op * tmp;
            tmp = i;
            op = -1;
            break;
        default:
            break;
        }
    }
    sum += op * tmp;
    return sum == 0;
}

inline bool next(char* ops)
{
    for (int i=n-1; i>=1; --i) {
        switch (ops[i]) {
        case ' ':
            ops[i] = '+';
            return true;
        case '+':
            ops[i] = '-';
            return true;
        case '-':
            ops[i] = ' ';
            break;
        default:
            break;
        }
    }
    return false;
}

inline void out(const char* ops)
{
    for (int i=1; i<=n-1; ++i) {
        fout << i << ops[i];
    }
    fout << n << endl;
}

int main()
{
    fin >> n;
    memset(ops, ' ', OP_LEN); 
    do {
        if (isok(ops)) {
            out(ops);
        }
    } while (next(ops));
    return 0;
}
