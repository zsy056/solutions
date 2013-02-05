/* 
ID: zsy
LANG: C++
PROG: concom
*/
#include <iostream>
#include <fstream>

#define PROG "concom"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define NUM_MAX 110

int n;
int percent[NUM_MAX][NUM_MAX] = {{0}};
bool result[NUM_MAX][NUM_MAX] = {{false}};
bool flag = true;

int main()
{
    in >> n;
    for (int i=0; i<n; ++i) {
        int a, b, per;
        in >> a >> b >> per;
        percent[a][b] = per;
    }
    for (int i=0; i<NUM_MAX; ++i) {
        percent[i][i] = 100;
        result[i][i] = true;
    }

    while (flag) {
        flag = false;
        for (int i=0; i<NUM_MAX; ++i) {
            for (int j=0; j<NUM_MAX; ++j) {
                if (result[i][j]) continue;
                if (percent[i][j] > 50 && !result[i][j]) {
                    result[i][j] = true;
                    flag = true;
                    continue;
                }
                int sum = 0;
                for (int k=0; k<NUM_MAX; ++k) {
                    if (result[i][k]) sum += percent[k][j];
                }
                if (sum > 50) {
                    result[i][j] = true;
                    flag = true;
                }
            }
        }

    }

    for (int i=0; i<NUM_MAX; ++i) {
        for (int j=0; j<NUM_MAX; ++j) {
            if (result[i][j] && i!=j) {
                out << i << " " << j << endl;
            }
        }
    }

    return 0;
}
