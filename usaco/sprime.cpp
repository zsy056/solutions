/* 
ID: zsy
LANG: C++
PROG: sprime
*/
#include <cmath>
#include <iostream>
#include <fstream>
#include <queue>

#define PROG "sprime"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int n;
int curr;
queue<int> res;

inline bool isprime(int x)
{
    int sx = (int) sqrt(x);
    for (int i=2; i<=sx; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

inline int getdigi(int num)
{
    int digi = 0;
    while (num > 0) {
        ++digi;
        num /= 10;
    }
    return digi;
}

int main()
{
    fin >> n;
    for(int i=2; i<10; ++i) {
        if (isprime(i))
            res.push(i);
    }
    while (res.size() > 0) {
        int t = res.front();
        res.pop();
        if (getdigi(t) > n)
            break;
        if (getdigi(t) == n)
            fout << t << endl;
        for (int i=0; i<10; ++i) {
            int tmp = t*10 + i;
            if (isprime(tmp))
                res.push(tmp);
        }
    }
    return 0;
}
