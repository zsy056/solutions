/* 
ID: zsy
LANG: C++
PROG: milk3 
*/
#include <cstring>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

ofstream fout("milk3.out");
ifstream fin("milk3.in");

char r[21][21][21];
int cap[3];
set<char> res;

void search(int* now);

void move(int f, int t, int* now)
{
    int tmp[3];
    memcpy(tmp, now, sizeof(now[0])*3);
    if (now[f] + now[t] > cap[t]) {
        now[f] -= cap[t] - now[t];
        now[t] = cap[t];
    } else {
        now[t] += now[f];
        now[f] = 0;
    }
    if (now[0] == 0)
        res.insert(now[2]);
    if (r[now[0]][now[1]][now[2]] != 1) {
        r[now[0]][now[1]][now[2]] = 1;
        search(now);
    }
    memcpy(now, tmp, sizeof(now[0])*3);
}

void search(int* now)
{
    move(0, 1, now);
    move(0, 2, now);
    move(1, 0, now);
    move(1, 2, now);
    move(2, 0, now);
    move(2, 1, now);
}

int main()
{
    memset(r, 0, sizeof(r));
    fin >> cap[0] >> cap[1] >> cap[2];
    int now[3];
    now[0] = now[1] = 0;
    now[2] = cap[2];
    search(now);
    set<char>::iterator i=res.begin();
    fout << (int)*i;
    for ( ++i;i!=res.end(); ++i) {
        fout << ' ' << (int)*i;
    }
    fout << endl;
    return 0;
}
