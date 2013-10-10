/* 
ID: zsy
LANG: C++
PROG: spin 
*/
#include <cstring>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define PROG "spin"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define NUM_WHEEL 5
#define WHEEL_DEGREE 360

struct Space {
    int start;
    int extent;
    Space(): start(0), extent(0) {}
};

int speed[NUM_WHEEL] = { 0 };
int pos[NUM_WHEEL] = { 0 };
int wheel[WHEEL_DEGREE] = { 0 };
vector<Space> spaces[NUM_WHEEL];

int main()
{
    for (int i=0; i<NUM_WHEEL; ++i) {
        in >> speed[i];
        int n;
        in >> n;
        for (int j=0; j<n; ++j) {
            Space space;
            in >> space.start >> space.extent;
            spaces[i].push_back(space);
        }
    }
    int t = 0;
    bool flag = false;
    for (; t<WHEEL_DEGREE; ++t) {
        for (int i=0; i<NUM_WHEEL; ++i) {
            for (size_t j=0; j<spaces[i].size(); ++j) {
                for (int k=0; k<=spaces[i][j].extent; ++k) {
                    int tpos = (pos[i] + spaces[i][j].start + k) % WHEEL_DEGREE;
                    if (wheel[tpos] == i) {
                        wheel[tpos] = i + 1;
                        if (i == NUM_WHEEL - 1) {
                            flag = true;
                            goto finish;
                        }
                    }
                }
            }
            pos[i] = (pos[i] + speed[i]) % WHEEL_DEGREE;
        }
        memset(wheel, 0, sizeof(wheel));
    }
finish:
    if (flag) {
        out << t << endl;
    } else {
        out << "none" << endl;
    }
    return 0;
}
