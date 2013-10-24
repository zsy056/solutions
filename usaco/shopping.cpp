/* 
ID: zsy
LANG: C++
PROG: shopping 
*/
#include <climits>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

#define PROG "shopping"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define MAX_PRODUCT 8
#define CMAX 1000

struct item {
    int product;
    int number;
    item(): product(0), number(0) {}
};

struct offer {
    vector<item> items;
    int reduce;
    int total;
    offer(): reduce(0), total(0) {}
};

bool operator<(const offer& lv, const offer& rv)
{
    return lv.total > rv.total;
}

vector<offer> offers;
size_t s = 0;
int b = 0;
int prices[MAX_PRODUCT] = { 0 };
int idx[CMAX] = {0};
int rmax = 0;
int origin = 0;
int spend[MAX_PRODUCT][MAX_PRODUCT][MAX_PRODUCT][MAX_PRODUCT][MAX_PRODUCT];
int need[MAX_PRODUCT] = {0};

int main()
{
    in >> s;
    for (size_t i=0; i<s; ++i) {
        offers.push_back(offer());
        int n;
        in >> n;
        for (int j=0; j<n; ++j) {
            item it;
            in >> it.product >> it.number;
            offers[i].items.push_back(it);
            offers[i].total += it.number;
        }
        in >> offers[i].reduce;
    }
    in >> b;
    for (int i=0; i<b; ++i) {
        int c, num;
        in >> c;
        in >> num;
        idx[c] = i;
        need[i] = num;
        in >> prices[i];
        origin += num * prices[c];
    }
    for (int i=0; i<=need[0]; ++i) {
        for (int j=0; j<=need[1]; ++j) {
            for (int k=0; k<=need[2]; ++k) {
                for (int x=0; x<=need[3]; ++x) {
                    for (int y=0; y<=need[4]; ++y) {
                        spend[i][j][k][x][y] = i*prices[0] + j*prices[1]
                            + k*prices[2] + x*prices[3] + y*prices[4];
                    }
                }
            }
        }
    }
    for (int i=0; i<=need[0]; ++i) {
        for (int j=0; j<=need[1]; ++j) {
            for (int k=0; k<=need[2]; ++k) {
                for (int x=0; x<=need[3]; ++x) {
                    for (int y=0; y<=need[4]; ++y) {
                        for (size_t o=0; o<offers.size(); ++o) {
                            int has[MAX_PRODUCT] = {i, j, k, x, y}; 
                            for (size_t m=0; m<offers[o].items.size(); ++m) {
                                has[idx[offers[o].items[m].product]] +=
                                    offers[o].items[m].number;
                            }
                            bool valid = true;
                            for (int m=0; m<b; ++m) {
                                if (has[m] > need[m]) {
                                    valid = false;
                                    break;
                                }
                            }
                            if (valid) {
                                int nspend = spend[i][j][k][x][y] + offers[o].reduce;
                                if (spend[has[0]][has[1]][has[2]][has[3]][has[4]] > nspend){
                                    spend[has[0]][has[1]][has[2]][has[3]][has[4]] = nspend;
                                }
                            }
                        } 
                    }
                }
            }
        }
    }
    out << spend[need[0]][need[1]][need[2]][need[3]][need[4]] << endl;
    return 0;
}
