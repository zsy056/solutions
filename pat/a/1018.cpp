#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 600

using namespace std;

int cpref = 0;
int n = 0;
int sp = 0;
int m = 0;
int c[MAX];
int cmap[MAX][MAX];
vector<int> pres[MAX];
vector<vector<int> > paths;

inline void di()
{
    char unknown[MAX];
    memset(unknown, 1, sizeof(unknown[0])*(n+1));
    int dist[MAX];
    memset(dist, 9999, sizeof(dist[0])*(n+1));
    dist[0] = 0;
    while(true) {
        int sunknown = -1;
        int sdist = 10000;
        for(int i=0; i<n+1; ++i){
            if(unknown[i]==1 && i!=sunknown && dist[i]<sdist){
                sdist = dist[i];
                sunknown = i;
            }
        }
        if(sunknown==-1) break;
        for(int i=0; i<n+1; ++i){
            if(unknown[i]==1 && i!=sunknown && cmap[i][sunknown]!=-1){
                if(cmap[i][sunknown]+sdist<dist[i]){
                    dist[i] = cmap[i][sunknown] + sdist;
                    pres[i].clear();
                    pres[i].push_back(sunknown);
                    dist[i] = cmap[i][sunknown] + sdist;
                }  else if(cmap[i][sunknown]+sdist==dist[i]){
                    pres[i].push_back(sunknown);
                }
            }
        }
        unknown[sunknown] = 0;
    }
}

void dfs(int root, vector<int>* path)
{
    path->push_back(root);
    if(root==0){
        paths.push_back(*path);
    } else {
        for(int i=0; i<pres[root].size(); ++i){
            dfs(pres[root][i], path);
        }
    }
    path->pop_back();
}

inline void getpaths()
{
    di();
    vector<int> path;
    dfs(sp, &path);
    for(int i=0; i<paths.size(); ++i){
        int send = 0;
        int curr = 0;
        reverse(paths[i].begin(), paths[i].end());
        for(int j=1; j<paths[i].size(); ++j){
            if(c[paths[i][j]]>cpref){
                curr = curr + c[paths[i][j]] - cpref;
            } else if(c[paths[i][j]]<cpref){
                if(curr >= cpref-c[paths[i][j]]){
                    curr = curr - (cpref -c[paths[i][j]]);
                } else if(curr < cpref-c[paths[i][j]]){
                    send = send - (cpref-c[paths[i][j]]-curr);
                    curr = 0;
                }
            }
        }
        paths[i].push_back(-send);
        paths[i].push_back(curr);
    }
    int minsend = 9999;
    int minback = 9999;
    int idx = 0;
    for(int i=0; i<paths.size(); ++i){
        if(minsend>paths[i][paths[i].size()-2]){
            idx = i;
            minsend = paths[i][paths[i].size()-2];
            minback = paths[i].back();
        } else if(minsend==paths[i][paths[i].size()-2] 
            && minback>paths[i].back()){
            idx = i;
            minback = paths[i].back();
        }
    }
    printf("%d ", paths[idx][paths[idx].size()-2]);
    for(int i=0; i<paths[idx].size()-3; ++i){
        printf("%d->", paths[idx][i]);
    }
    printf("%d ", paths[idx][paths[idx].size()-3]);
    printf("%d\n", paths[idx].back());
}

int main()
{
    scanf("%d %d %d %d", &cpref, &n, &sp, &m);
    cpref = cpref / 2;

    if(n<=0) return 0;
    for(int i=0; i<n; ++i){
        scanf("%d", &(c[i+1]));
    }
    for(int i=0; i<n+1; ++i) {
        for(int j=0; j<n+1; ++j){
            cmap[i][j] = -1;
        }
    }
    for(int i=0; i<m; ++i){
        int si, sj, tij;
        scanf("%d %d %d", &si, &sj, &tij);
        cmap[si][sj] = cmap[sj][si] = tij;
    }

    getpaths();

    return 0;
}
