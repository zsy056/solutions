/* 
ID: zsy
LANG: C++
PROG: maze1 
*/
#include <cstring>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define PROG "maze1"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define W_MAX 38
#define H_MAX 100

struct Pos {
    int i;
    int j;
    bool visited;
    int dep;
    vector<int> dep_vec;
    Pos(): i(-1), j(-1), visited(false), dep(1) {}
    Pos(int i, int j, bool out): i(i), j(j),
    visited(false), dep(1) {}
};

int w;
int h;
char maze[2*H_MAX+1][2*W_MAX+1];
vector<Pos*> neighbor[H_MAX][W_MAX];
Pos  nodes[H_MAX][W_MAX];
vector<Pos*> out_node;

int bfs(int i, int j)
{
    int curr_dep = 1;
    queue<Pos*> q;
    nodes[i][j].visited = true;
    nodes[i][j].dep_vec.push_back(1);
    q.push(&nodes[i][j]);
    while (q.size() > 0) {
        Pos* curr = q.front();
        curr_dep = curr->dep;
        q.pop();
        for (vector<Pos*>::iterator it=neighbor[curr->i][curr->j].begin();
            it != neighbor[curr->i][curr->j].end(); ++it) {
            Pos* nei = *it;
            if (!nei->visited) {
                nei->dep = curr_dep + 1; 
                nei->dep_vec.push_back(nei->dep);
                nei->visited = true;
                q.push(nei);
            }
        }
    }
    return curr_dep;
}

void clean()
{
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            nodes[i][j].visited = false;
            nodes[i][j].dep = 1;
        }
    }
}

int main()
{
    memset(maze, sizeof(maze), ' ');
    string tmp;
    getline(in, tmp);
    sscanf(tmp.c_str(), "%d %d", &w, &h);
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            nodes[i][j].i = i;
            nodes[i][j].j = j;
        }
    }
    for (int i=0; i<2*h+1; ++i) {
        getline(in, tmp);
        for (size_t j=0; j<tmp.size(); ++j) {
            maze[i][j] = tmp[j];
        }
    }
    // get connections
    for (int i=2; i<2*h; i+=2) {
        for (int j=1; j<2*w; j+=2) {
            if (maze[i][j] == ' ') {
                int x = (i-2) / 2;
                int y = j/2;
                neighbor[x][y].push_back(&nodes[x+1][y]);
                neighbor[x+1][y].push_back(&nodes[x][y]);
            }
        }
    }
    for (int i=1; i<2*h; i+=2) {
        for (int j=2; j<2*w; j+=2) {
            if (maze[i][j] == ' ') {
                int x = i / 2;
                int y = (j-2) / 2; 
                neighbor[x][y].push_back(&nodes[x][y+1]);
                neighbor[x][y+1].push_back(&nodes[x][y]);
            }
        }
    }
    // check open nodes
    for (int j=1; j<2*w+1; j+=2) {
        if (maze[0][j] == ' ') {
            out_node.push_back(&nodes[0][j/2]);
        }
        if (maze[2*h][j] == ' ') {
            out_node.push_back(&nodes[h-1][j/2]);
        }
    }
    //for (int i=0; i<2*h+1; ++i) {
    //    for (int j=0; j<2*w+1; ++j) {
    //        printf("%c", maze[i][j]);
    //    }
    //    puts("");
    //}
    for (int i=1; i<2*h+1; i+=2) {
        if (maze[i][0] == ' ') {
            out_node.push_back(&nodes[i/2][0]);
        }
        if (maze[i][2*w] == ' ') {
            out_node.push_back(&nodes[i/2][w-1]);
        }
    }
    for (vector<Pos*>::iterator it=out_node.begin();
            it!=out_node.end(); ++it) {
        Pos* pos = *it;
        bfs(pos->i, pos->j);
        clean();
    }
    int max_dep = INT_MIN;
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            int dep = *min_element(nodes[i][j].dep_vec.begin(),
                    nodes[i][j].dep_vec.end());
            if (dep > max_dep) {
                max_dep = dep;
            }
        }
    }
    out << max_dep << endl;
    
    return 0;
}
