/* 
ID: zsy
LANG: C++
PROG: fact4 
*/
#include <stdint.h>
#include <cmath>
#include <cstring>

#include <iostream>
#include <fstream>

#define PROG "fact4"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

int n;

int mul(char* a, int b)
{
    int carry = 0;
    int len = strlen(a);
    int i = 0;
    for (; i<len; ++i) {
        int tmp = (a[i] - '0') * b + carry;
        a[i] = tmp % 10 + '0';
        carry = tmp / 10;
    }
    while (carry > 0) {
        a[i] = carry % 10 + '0';
        carry /= 10;
        ++i;
    }
    a[i] = '\0';
    return i;
}

void remove_tail_zeros(char* a, int len)
{
    int i = 0;
    for (; i<len; ++i) {
        if (a[i] != '0')
            break;
    }
    strcpy(a, a+i);
}

int main()
{
    in >> n;
    char res[4096] = {0};
    res[0] = '1';
    for (int i=1; i<=n; ++i) {
        int len = mul(res, i);
        remove_tail_zeros(res, len);
        //out << res << endl;
    }
    out << res[0] << endl;
    return 0;
}
