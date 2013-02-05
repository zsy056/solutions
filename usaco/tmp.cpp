/* 
ID: zsy
LANG: C++
PROG: 
*/
#include <iostream>
#include <fstream>

#define PROG ""

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

int main()
{
    return 0;
}
