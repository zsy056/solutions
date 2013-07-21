/*
ID: zsy
LANG: C++
PROG: cowtour
*/
#include <cstring>
#include <cmath>
#include <cfloat>
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <queue>

#define PROG "cowtour"

using namespace std;


#define NMAX 160

struct Pasture {
    int x;
    int y;
    double maxdist;
};

Pasture pastures[NMAX];
char connect[NMAX][NMAX];
double dists[NMAX][NMAX] = {0};
int n = 0;

inline double dist(const Pasture& a, const Pasture& b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

inline void get_dist(double outdists[NMAX][NMAX]) {
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (outdists[i][k] == -1 || outdists[k][j] == -1) {
                    continue;
                }
                if (outdists[i][k] + outdists[k][j] < outdists[i][j]
                        || outdists[i][j] == -1) {
                    outdists[i][j] = outdists[i][k] + outdists[k][j];
                }
            }
        }
    }
}

inline double find() {
    // find max distance for each pasture
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (dists[i][j] != -1 && pastures[i].maxdist < dists[i][j]) {
                pastures[i].maxdist = dists[i][j];
            }
        }
    }
    // The new D with new cow path for field
    double min_d = DBL_MAX;
    int idxs[2] = {0};
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (dists[i][j] == -1) {
                double tmp = pastures[i].maxdist + pastures[j].maxdist
                    + dist(pastures[i], pastures[j]);
                if (min_d > tmp) {
                    min_d = tmp;
                    idxs[0] = i;
                    idxs[1] = j;
                }
            }
        }
    }
    // find D for this field
    double max_d = DBL_MIN;
    for(int idx=0; idx<2; ++idx) {
        int k = idxs[idx];
        for (int i=0; i<n; ++i) {
            if (dists[i][k] != -1 && pastures[i].maxdist > max_d) {
                max_d = pastures[i].maxdist;
            }
        }
    }
    return max(min_d, max_d);
}

int main()
{
    // input
    FILE* fin = fopen(PROG ".in", "r");
    fscanf(fin, "%d", &n);
    for (int i=0; i<n; ++i) {
        fscanf(fin, "%d %d", &pastures[i].x, &pastures[i].y);
    }
    for (int i=0; i<n; ++i) {
        fscanf(fin, "%s", connect[i]);
    }
    fclose(fin);
    // init
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (i == j) {
                dists[i][j] = 0;
            } else if (connect[i][j] == '1') {
                if (dists[i][j] == 0) {
                    dists[i][j] = dist(pastures[i], pastures[j]);
                } else {
                    dists[i][j] = dists[j][i];
                }
            } else {
                dists[i][j] = -1;
            }
        }
    }
    get_dist(dists);
    double res = find();
    FILE* fout = fopen(PROG ".out", "w");
    fprintf(fout, "%.6lf\n", res);
    fclose(fout);
    return 0;
}
