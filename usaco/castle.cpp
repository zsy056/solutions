/* 
ID: zsy
LANG: C++
PROG: castle 
*/
#include <iostream>
#include <fstream>

#define PROG "castle"
#define MAX_NUM 50
#define VISITED_ROOT -2

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int m = 0;
int n = 0;
int roomnum = 0;
int maxsize = 0;

int newmaxsize = 0;
int rx, ry;
char dir = 'X';

struct node {
    int wall;
    int parentx;
    int parenty;
    node(): parentx(-1), parenty(1) {}
};

node nodes[MAX_NUM][MAX_NUM];

void dfs(int x, int y, int rootpos)
{
    if (x<0 || x>=n || y<0 || y>=m || nodes[x][y].parentx==VISITED_ROOT
        || ((nodes[x][y].parentx<<16)+nodes[x][y].parenty)==rootpos)
        return;
    if (rootpos == -1) {
        nodes[x][y].parentx = VISITED_ROOT;
        rootpos = (x << 16) + y;
    } else {
        nodes[x][y].parentx = rootpos >> 16;
        nodes[x][y].parenty = rootpos & 0xFFFF;
        ++nodes[nodes[x][y].parentx][nodes[x][y].parenty].parenty;
    }
    if ((nodes[x][y].wall & 1) == 0)
        dfs(x, y-1, rootpos);
    if ((nodes[x][y].wall & 2) == 0)
        dfs(x-1, y, rootpos);
    if ((nodes[x][y].wall & 4) == 0)
        dfs(x, y+1, rootpos);
    if ((nodes[x][y].wall & 8) == 0)
        dfs(x+1, y, rootpos);
}

inline int getsize(int x, int y)
{
    if (nodes[x][y].parentx == VISITED_ROOT)
        return nodes[x][y].parenty;
    return nodes[nodes[x][y].parentx][nodes[x][y].parenty].parenty;
}

inline int isto(int x1, int y1, int x2, int y2)
{
    int parentx1 = nodes[x1][y1].parentx;
    int parenty1 = nodes[x1][y1].parenty;
    int parentx2 = nodes[x2][y2].parentx;
    int parenty2 = nodes[x2][y2].parenty;
    if (nodes[x1][y1].parentx == VISITED_ROOT) {
        parentx1 = x1;
        parenty1 = y1;
    }
    if (nodes[x2][y2].parentx == VISITED_ROOT) {
        parentx2 = x2;
        parenty2 = y2;
    }
    return parentx1 == parentx2 && parenty1 == parenty2;
}

int main()
{
    fin >> m >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            fin >> nodes[i][j].wall;
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (nodes[i][j].parentx == -1) {
                dfs(i, j, -1);
                ++roomnum;
                if (nodes[i][j].parenty > maxsize) {
                    maxsize = nodes[i][j].parenty;
                }
            }
        }
    }
    for (int j=m-1; j>=0; --j) {
        for (int i=0; i<n; ++i) {
            if (j<m-1 && (nodes[i][j].wall & 4) != 0
                && !isto(i, j+1, i, j)) {
                int size = getsize(i, j+1) + getsize(i, j);
                //cout << i << ' '<< j << endl << size << endl;
                if (size >= newmaxsize) {
                    newmaxsize = size;
                    rx = i;
                    ry = j;
                    dir = 'E';
                }
            }
            if (i>0 && (nodes[i][j].wall & 2) != 0
                && !isto(i-1, j, i, j)) {
                int size = getsize(i-1, j) + getsize(i, j);
                //cout << i << ' '<< j << endl << size << endl;
                if (size >= newmaxsize) {
                    newmaxsize = size;
                    rx = i;
                    ry = j;
                    dir = 'N';
                }
            }
            
        }
    }
    fout << roomnum << endl
        << maxsize << endl
        << newmaxsize << endl
        << rx+1 << ' ' << ry+1 << ' ' << dir << endl;
    return 0;
}
