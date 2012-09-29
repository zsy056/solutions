/* 
ID: zsy
LANG: C++
PROG: lamps
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#define PROG "lamps"

using namespace std;

struct Config {
    Config() {};
    Config(int n, int val): cfg(n, val) {}
    vector<int> cfg;
};

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
int lamp_num;
int n;
set<Config> res;

bool operator==(const Config& lv, const Config& rv)
{
    if (lv.cfg.size() != rv.cfg.size())
        return false;
    for (size_t i=0; i<lv.cfg.size(); ++i) {
        if (lv.cfg[i] != -1 && rv.cfg[i] != -1 && lv.cfg[i] != rv.cfg[i])
            return false;
    }
    return true;
}

bool operator<(const Config& lv, const Config& rv)
{
    return lv.cfg < rv.cfg;
}

ostream& operator<<(ostream& os, const Config& v)
{
    for (vector<int>::const_iterator i=v.cfg.begin(); i!=v.cfg.end(); ++i) {
        os << *i;
    }
    return os;
}

inline void bt1(Config* conf)
{
    for (vector<int>::iterator i=conf->cfg.begin(); i!=conf->cfg.end();
        ++i) {
        *i = 1 - (*i);
    }
}

inline void bt2(Config* conf)
{
    for (size_t i=1; i<conf->cfg.size(); i+=2) {
        conf->cfg[i] = 1 - conf->cfg[i];
    }
}

inline void bt3(Config* conf)
{
    for (size_t i=0; i<conf->cfg.size(); i+=2) {
        conf->cfg[i] = 1 - conf->cfg[i];
    }
}

inline void bt4(Config* conf)
{
    for (size_t i=0; i*3<conf->cfg.size(); ++i) {
        conf->cfg[i*3] = 1 - conf->cfg[i*3];
    }
}

void dfs(int dep, Config* final, Config* prev, int preNum)
{
    if (*prev==*final && (n-dep)%2==0) {
        res.insert(*prev);
    }
    if (dep >= n) {
        return;
    }
    if (preNum != 1) {
        bt1(prev);
        dfs(dep + 1, final, prev, 1);
        bt1(prev);
    }
    if (preNum != 2) {
        bt2(prev);
        dfs(dep + 1, final, prev, 2);
        bt2(prev);
    }
    if (preNum != 3) {
        bt3(prev);
        dfs(dep + 1, final, prev, 3);
        bt3(prev);
    }
    if (preNum != 4) {
        bt4(prev);
        dfs(dep + 1, final, prev, 4);
        bt4(prev);
    }
}

inline void cal(Config* final)
{
    Config start(lamp_num, 1); 
    dfs(0, final, &start, -1);
}

int main()
{
    fin >> lamp_num >> n;
    Config final(lamp_num, -1);
    int tmp;
    while (true) {
        fin >> tmp;
        if (tmp == -1)
            break;
        final.cfg[tmp-1] = 1;
    }
    while (true) {
        fin >> tmp;
        if (tmp == -1)
            break;
        final.cfg[tmp-1] = 0;
    }
    if (n <= 4) {
        cal(&final);
    } else {
        n = 3;
        cal(&final);
        n = 4;
        cal(&final);
    }
    if (res.size() == 0) {
        fout << "IMPOSSIBLE" << endl;
    }
    for (set<Config>::iterator i=res.begin(); i!=res.end(); ++i) {
        fout << *i << endl;
    }
    return 0;
}
