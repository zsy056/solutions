/* 
ID: zsy
LANG: C++
PROG: fence 
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define PROG "fence"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define MAX_INTER 510

int num_fences = 0;
int edges[MAX_INTER][MAX_INTER] = { 0 };
int degree[MAX_INTER] = {0};
int max_inter = 0;

vector<int> path;

void find_path(int node)
{
    if (degree[node] == 0)
        path.push_back(node);
    else {
        while (degree[node] != 0) {
            for (int i=1; i<=max_inter; ++i) {
                if (edges[node][i] != 0) {
                    --edges[node][i]; --edges[i][node];
                    --degree[i]; --degree[node];
                    find_path(i);
                }
            }
        }
        path.push_back(node);
    }
}

int main()
{
    in >> num_fences;
    for (int i=0; i<num_fences; ++i) {
        int a, b;
        in >> a >> b;
        ++edges[a][b]; ++edges[b][a];
        ++degree[a]; ++degree[b];
        max_inter = max(max_inter, max(a, b));
    }
    // start with node with odd degree if possible
    int start = 1;
    for (int i=1; i<=max_inter; ++i) {
        if (degree[i] % 2 != 0) {
            start = i;
            break;
        }
    }
    find_path(start);
    for (size_t i=0; i<path.size(); ++i) {
        out << path[path.size()-1-i] << endl;
    }
    return 0;
}
