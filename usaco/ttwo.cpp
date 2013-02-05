/* 
ID: zsy
LANG: C++
PROG: ttwo 
*/
#include <cstring>
#include <iostream>
#include <fstream>

#define PROG "ttwo"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define NUM 10

struct Pos {
    int i;
    int j;
    int face;
    Pos(int i, int j, int face): i(i), j(j), face(face) {}
};

inline bool operator==(const Pos& lv, const Pos& rv)
{
    return lv.i == rv.i && lv.j == rv.j;
}

char map[NUM+2][NUM+2];
Pos cow(0, 0, 'N');
Pos far(0, 0, 'N');

inline void mv(Pos* pos)
{
    switch (pos->face) {
    case 'N':
        if (map[pos->i-1][pos->j] == '*') {
            pos->face = 'E';
        } else {
            pos->i -= 1;
        }
        break;
    case 'E':
        if (map[pos->i][pos->j+1] == '*') {
            pos->face = 'S';
        } else {
            pos->j += 1;
        }
        break;
    case 'S':
        if (map[pos->i+1][pos->j] == '*') {
            pos->face = 'W';
        } else {
            pos->i += 1;
        }
        break;
    case 'W':
        if (map[pos->i][pos->j-1] == '*') {
            pos->face = 'N';
        } else {
            pos->j -= 1;
        }
        break;
    default:
        break;
    }
}

int main()
{
    memset(map, '*', sizeof map);
    for (int i=1; i<=NUM; ++i) {
        for (int j=1; j<=NUM; ++j) {
            char c;
            in >> c;
            map[i][j] = c;
            if (c == 'C') {
                cow.i = i;
                cow.j = j;
            } else if (c == 'F') {
                far.i = i;
                far.j = j;
            }
        }
    }
    int time = 0;
    bool flag = false;
    while (time < 1000) {
        if (cow == far) {
            flag = true;
            break;
        }
        mv(&cow);
        mv(&far);
        ++time;
    }
    if (flag) {
        out << time << endl;
    } else {
        out << 0 << endl;
    }
    return 0;
}
