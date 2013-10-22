/* 
ID: zsy
LANG: C++
PROG: _NAME 
*/
#include <iostream>
#include <fstream>

#define PROG "_NAME"

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
