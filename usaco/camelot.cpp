/* 
ID: zsy
LANG: C++
PROG: camelot 
*/
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

#define PROG "camelot"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define MAX_C 28
#define MAX_R 32
#define MOVE_N 8

struct pos {
    int r;
    int c;
    int step;
    int king_dist;
    pos(): r(0), c(0), step(0), king_dist(0) {}
    pos(int r, int c, int step = 0, int king_dist = 0): r(r), c(c), step(step),
    king_dist(king_dist) {}
};

bool operator<(const pos& lv, const pos& rv)
{
    return lv.step > rv.step || (lv.step == rv.step 
            && lv.king_dist > rv.king_dist);
}

int r = 0;
int c = 0;
pos king;
vector<pos> knights;
int steps[MAX_R][MAX_C];
int min_king_mv[MAX_R][MAX_C];
size_t conn[MAX_R][MAX_C];
pos knight_move[] = {pos(1, 2), pos(-1, -2), pos(1, -2), pos(-1, 2),
    pos(2, 1), pos(-2, -1), pos(-2, 1), pos(2, -1)};
pos king_move[] = {pos(0, 1), pos(0, -1), pos(-1, 0), pos(1, 0),
    pos(1, 1), pos(-1, 1), pos(1, -1), pos(-1, -1)};

inline bool valid_move(const set<int> board[MAX_R][MAX_C], int knight, int new_c, int new_r, int step)
{
    return new_c >= 0 && new_c < c && new_r >= 1 && new_r <= r
        && board[new_r][new_c].find(knight) == board[new_r][new_c].end();
}

inline void knight_travel(int idx)
{
#ifdef DEBUG
    cout << "_____" << idx << endl;
#endif
    set<int> board[MAX_R][MAX_C];
    priority_queue<pos> q;
    q.push(knights[idx]);
    board[knights[idx].r][knights[idx].c].insert(idx);
    ++conn[knights[idx].r][knights[idx].c];
    while (q.size() != 0) {
        pos start = q.top();
        if (min_king_mv[start.r][start.c] > start.king_dist) {
            min_king_mv[start.r][start.c] = start.king_dist;
        }
#ifdef DEBUG
        cout << (char) (start.c + 'A') << " " << start.r << " "
            << min_king_mv[start.r][start.c]  << " " << start.step << endl;
#endif
        q.pop();
        for (int i=0; i<MOVE_N; ++i) {
            int new_c = start.c + knight_move[i].c;
            int new_r = start.r + knight_move[i].r;
            if (valid_move(board, idx, new_c, new_r, start.step + 1)) {  
                int king_dist = min(start.king_dist,
                        max(abs(king.c-new_c), abs(king.r-new_r)));
                q.push(pos(new_r, new_c, start.step+1, king_dist));
                steps[new_r][new_c] += start.step + 1;
                board[new_r][new_c].insert(idx);
                ++conn[new_r][new_c];
            } 
        } 
    }
}

inline int min_step()
{
    int min_s = INT_MAX;
    for (int i=1; i<=r; ++i) {
        for (int j=0; j<c; ++j) {
            // not reachable 
            if (conn[i][j] != knights.size())
                continue;
            int step = min_king_mv[i][j];
            //cout << min_king_mv[i][j] << endl;
            step += steps[i][j];
            /*for (map<int, int>::iterator it=board[i][j].begin();
              it!=board[i][j].end() && step < min_s; ++it) {
              step += it->second; 
              }*/
            cout << step << " "
                    << (char) (j + 'A') << " " << i 
                    << "  " << conn[i][j] << endl;
            cout << min_king_mv[i][j] << endl;
            if (step < min_s) {
                min_s = step;
            }
        }
    }
    return min_s;
}

int main()
{
    in >> r >> c;
    char tmpc;
    in >> tmpc >> king.r;
    king.c = tmpc - 'A';
    while (true) {
        in >> tmpc;
        if (!in.good()) {
            break;
        }
        pos p;
        in >> p.r;
        p.c = tmpc - 'A';
        p.king_dist = max(abs(king.c - p.c), abs(king.r - p.r));
        knights.push_back(p);
    }
    for (int i=0; i<MAX_R; ++i) {
        for (int j=0; j<MAX_C; ++j) {
            min_king_mv[i][j] = max(abs(king.c - j), abs(king.r - i));
            steps[i][j] = 0;
            conn[i][j] = 0;
        }
    }
    for (size_t i=0; i<knights.size(); ++i) {
        knight_travel(i);  
    }
    int min_s = min_step();
    min_s = knights.size() == 0 ? 0 : min_s;
    out << min_s << endl;
    return 0;
}
