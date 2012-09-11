/* 
ID: zsy
LANG: C++
PROG: runround
*/
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

#define PROG "runround"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
#define DIGI 10

inline bool all_visited(int* digis, int len)
{
    for (int i=0; i<len; ++i) {
        if (digis[i] == 0)
            return false;
    }
    return true;
}

inline bool is_unique(const char* src)
{
    char tmp[DIGI];
    strcpy(tmp, src);
    sort(tmp, tmp+strlen(tmp));
    for (int i=1; i<strlen(tmp); ++i) {
        if (tmp[i-1] == tmp[i]) {
            return false;
        }
    }
    return true;
}

inline bool is_runround(unsigned int n)
{
    int visited[DIGI]; 
    char digis[DIGI];
    memset(visited, 0, sizeof(visited));
    sprintf(digis, "%u", n); 
    if (!is_unique(digis))
        return false;
    int len = strlen(digis);
    int idx = 0;
    while (!all_visited(visited, len)) {
        if (visited[idx] == 0) {
            visited[idx] = 1;
            idx = (idx + digis[idx] - '0') % len;
#ifdef TEST
            cout << digis[idx];
#endif
        } else {
            return false;
        }
    }
#ifdef TEST
    cout << endl;
#endif
    if (idx == 0)
        return true;
    return false;
}

int main()
{
    int n;
    fin >> n;
    while(!is_runround(++n))
        ;
    fout << n << endl;
    return 0;
}
