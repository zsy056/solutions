#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define MAX 10001

typedef set<int> iset;

typedef map<int, set<int> > gra_t;

gra_t gra;
int coms[MAX];
int res[MAX];
int n = 0;

inline int min(int a, int b)
{
    return a<b ? a : b;
}

inline int max(int a, int b)
{
    return a>b ? a : b;
}

void dfs(int root, int x)
{
    coms[x] = root;
    gra_t::iterator it = gra.find(x);
    for(int i=0; i<n; ++i){
        if(x==i || coms[i]!=-1) continue;
        if(it==gra.end() || it->second.find(i)==it->second.end())
            continue;
        dfs(root, i);
    }
}

inline bool isconnected()
{
    for(int i=0; i<n; ++i) {
        coms[i] = -1;
    }
    for(int i=0; i<n; ++i){
        if(coms[i]!=-1) continue;
        coms[i] = i;
        for(int j=0; j<n; ++j){
            if(i==j) continue;
            gra_t::iterator it = gra.find(i);
            if(it!=gra.end() && it->second.find(j)!=it->second.end()) {
                dfs(i, j);
            }
        }
    }
    set<int> iset;
    for(int i=0; i<n; ++i){
        iset.insert(coms[i]);
    }
    int len = iset.size();
    if(len!=1){
        printf("Error: %d components\n", len);
        return false;
    }
    return true;
}

inline void bfs(int root, set<int>* maxleaf)
{
    queue<int> q;
    q.push(root);
    res[root] = 1;
    int maxdepth = 0;
    while(q.size()>0){
        int curr = q.front();
        int depth = res[curr];
        q.pop();
        if(depth>maxdepth) {
            maxdepth = depth;
        } 
        gra_t::iterator it = gra.find(curr);
        if(it==gra.end()) continue;
        for(iset::iterator i = it->second.begin();
            i != it->second.end(); ++i){
            if(res[*i]!=0) continue;
            res[*i] = depth + 1;
            q.push(*i);
        }
    }
    for(int i=0; i<n; ++i){
        if(res[i]==maxdepth){
            maxleaf->insert(i);
        }
    }
}

inline void droot()
{
    memset(res, 0, sizeof(res[0])*n);
    iset droots;
    bfs(0, &droots);
    memset(res, 0, sizeof(res[0])*n);
    bfs(*(droots.begin()), &droots);
    for(iset::iterator i=droots.begin(); i!=droots.end(); ++i){
        printf("%d\n", *i + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n-1; ++i){
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        --a; --b;
        gra_t::iterator it = gra.find(a);
        if(it == gra.end()) {
            set<int> tmp;
            tmp.insert(b);
            gra[a] = tmp;
        } else {
            it->second.insert(b);
        }
        it = gra.find(b);
        if(it == gra.end()) {
            set<int> tmp;
            tmp.insert(a);
            gra[b] = tmp;
        } else {
            it->second.insert(a);
        }
    }
    if(isconnected()){
        droot();
    }
    return 0;
}
