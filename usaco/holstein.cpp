/* 
ID: zsy
LANG: C++
PROG: holstein
*/
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

#define PROG "holstein"
#define NUM_VIT 26
#define VIT_AMT 1001

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");

int need[NUM_VIT];
int give[NUM_VIT][NUM_VIT];
int v = 0;
int g = 0;
int choose[NUM_VIT];
int now[NUM_VIT];
int counter = 0;

inline void init()
{
    memset(choose, 0, sizeof(choose));
    memcpy(now, need, sizeof(need));
}


inline bool is_ok()
{
    for (int i=0; i<v; ++i) {
        if (now[i] > 0) {
            return false;
        }
    }
    return true;
}

inline void choo(int dst)
{
    ++counter;
    choose[dst] = 1;
    for (int j=0; j<v; ++j) {
        now[j] -= give[dst][j];
        //cout << now[j] << ' ';
    }
    //cout << endl;
}

inline void unchoo(int dst)
{
    --counter;
    choose[dst] = 0;
    for (int j=0; j<v; ++j) {
        now[j] += give[dst][j];
    }
}

inline void pres(ostream& out)
{
    out << counter;
    for (int i=0; i<g; ++i) {
        if (choose[i] == 1) {
            out << ' ' << i+1;
        }
    }
    out << endl;
}

void cal(int begin, int to_choose)
{
    if (to_choose <= 0) {
        return;
    }
    for (int i=begin; i<g; ++i) {
        //cout << i << endl;
        choo(i); 
        if (is_ok()) {
            pres(fout);
            exit(EXIT_SUCCESS);
        }
        cal(i+1, to_choose-1);
        unchoo(i);
    }
}

int main()
{
    fin >> v;
    for (int i=0; i<v; ++i) {
        fin >> need[i];
    }
    fin >> g;
    for (int i=0; i<g; ++i) {
        for (int j=0; j<v; ++j) {
            fin >> give[i][j];
        }
    }
    init();
    for (int i=1; i<=g; ++i) {
        for (int j=0; j<=g-i; ++j) {
            //cout << i << ' ' << j << endl;
            cal(j, i);
        }
    }
    return 0;
}
