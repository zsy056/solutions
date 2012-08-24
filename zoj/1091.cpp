#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

#define MAX 9

struct Pos {
    int col;
    int row;
    int step;
    Pos(int col, int row, int step):
        col(col), row(row), step(step) {}
    Pos() {}
};

inline bool operator==(const Pos& lv, const Pos& rv)
{
    return lv.row==rv.row && lv.col==rv.col;
}


inline vector<Pos> getPos(const Pos& src, int step)
{
    vector<Pos> tmp;
    if(src.col<7 && src.row<8) {
        tmp.push_back(Pos(src.col+2, src.row+1, step));
    }
    if(src.col<8 && src.row<7) {
        tmp.push_back(Pos(src.col+1, src.row+2, step));
    }
    if(src.col<8 && src.row>2) {
        tmp.push_back(Pos(src.col+1, src.row-2, step));
    }
    if(src.col>2 && src.row<8) {
        tmp.push_back(Pos(src.col-2, src.row+1, step));
    }
    if(src.col>1 && src.row<7) {
        tmp.push_back(Pos(src.col-1, src.row+2, step));
    }
    if(src.col<7 && src.row>1) {
        tmp.push_back(Pos(src.col+2, src.row-1, step));
    }
    if(src.col>1 && src.row>2) {
        tmp.push_back(Pos(src.col-1, src.row-2, step));
    }
    if(src.col>2 && src.row>1) {
        tmp.push_back(Pos(src.col-2, src.row-1, step));
    }
    return tmp;
}

inline int bfs(const Pos& src, const Pos& des)
{
    if(src == des) {
        return 0;
    }
    queue<Pos> q;
    q.push(src);
    while(q.size()>0) {
        Pos tmp = q.front();
        q.pop();
        vector<Pos> nextPoses = getPos(tmp, tmp.step+1);
        //printf("%d %d \n", tmp.col, tmp.row);
        //getchar();
        for(size_t i=0; i<nextPoses.size(); ++i) {
            if(nextPoses[i] == des) {
                return nextPoses[i].step;
            }
            q.push(nextPoses[i]);
        }
    }
    return 0;
}

int main()
{
    int step;
    int c1, c2, r1, r2;
    char a[3], b[3];
    while(scanf("%s %s", a, b)==2) {
        c1 = a[0] - 'a' + 1;
        c2 = b[0] - 'a' + 1;
        r1 = a[1] - '0';
        r2 = b[1] - '0';
        step = bfs(Pos(c1, r1, 0), Pos(c2, r2, 0));
        printf("To get from %c%d to %c%d takes %d knight moves.\n",
            a[0], r1, b[0], r2, step);
    } 
    return 0;
}
