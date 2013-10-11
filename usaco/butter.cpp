/* 
ID: zsy
LANG: C++
PROG: butter 
*/
#include <climits>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#define PROG "butter"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define NUM_P 800
#define NUM_COW 500

int n = 0;
int p = 0;
int c = 0;
int num_cows[NUM_P] = { 0 };
int length[NUM_P][NUM_P];
int summary[NUM_P] = { 0 };

struct way{
    int node;
    int dist;
    way() {}
    way(int node, int dist): node(node), dist(dist) {}
    way(const way& src): node(src.node), dist(src.dist) {}
    way& operator=(const way& src)
    {
        node = src.node;
        dist = src.dist;
        return *this;
    }
};

vector<way> conn[NUM_P];

bool operator<(const way& lv, const way& rv)
{
    return lv.dist > rv.dist;
}

void shortest()
{
    bool found[NUM_P];
    priority_queue<way> queue;
    way tway;
    for (int i=0; i<p; ++i) {
        if (num_cows[i] == 0) continue;
        fill_n(found, NUM_P, false);
        queue.push(way(i, 0)); 
        length[i][i] = 0;
        while (queue.size() > 0) {
            tway = queue.top();
            queue.pop();
            if (found[tway.node]) continue;
            found[tway.node] = true;
            length[i][tway.node] = tway.dist;
            for (size_t j=0; j<conn[tway.node].size(); ++j) {
                if (found[conn[tway.node][j].node]) continue;
                queue.push(way(conn[tway.node][j].node, conn[tway.node][j].dist+ tway.dist)); 
            }
        }
    }
}

int main()
{
    in.sync_with_stdio(false);
    in >> n >> p >> c;
    for (int i=0; i<n; ++i) {
        int pas = 0;
        in >> pas;
        ++num_cows[pas - 1];
    }
    for (int i=0; i<p; ++i) {
        for (int j=0; j<p; ++j) {
            length[i][j] = 0;
        }
    }
    for (int i=0; i<c; ++i) {
        int a, b;
        in >> a >> b;
        --a; --b;
        int len;
        in >> len;
        conn[a].push_back(way(b, len));
        conn[b].push_back(way(a, len));
    }

    shortest();

    for (int i=0; i<p; ++i) {
        for (int j=0; j<p; ++j) {
            summary[j] += length[i][j] * num_cows[i];
        }
    }
    int min_len = INT_MAX;
    for (int i=0; i<p; ++i) {
        if (summary[i] < min_len) {
            min_len = summary[i];
        }
    }
    out << min_len << endl;

    return 0;
}
