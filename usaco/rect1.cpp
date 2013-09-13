/* 
ID: zsy
LANG: C++
PROG: rect1 
*/
#include <cstring>
#include <cstdio>

#include <iostream>
#include <fstream>         
#include <list>
#include <vector>
#include <memory>

#define PROG "rect1"

using namespace std;

FILE* out;
FILE* in;

#define MAXN 1010

int result[MAXN];

struct Region {
    int llx;
    int lly;
    int urx;
    int ury;
    Region(int llx, int lly, int urx, int ury):
        llx(llx), lly(lly), urx(urx), ury(ury) {}
};

struct Color {
    Region big_region;
    int color;
    Color(int llx, int lly, int urx, int ury, int color):
        big_region(llx, lly, urx, ury), color(color) {}
};

int n;
vector<Color> colors;

inline bool is_intersect(const Region& region1, const Region& region2)
{
    if (region1.urx < region2.llx || region1.llx > region2.urx
            || region1.lly > region2.ury || region1.ury < region2.lly) {
        return false;
    }
    return true;                             
}

inline int get_size(const Region& region)
{
    return (region.urx - region.llx) * (region.ury - region.lly);
}

inline list<Region>* split_region(const Region& to_split, const Region& spliter)
{
    list<Region>* new_regions = new list<Region>();
    int lx = to_split.llx, rx = to_split.urx;
    // left region
    if (to_split.llx < spliter.llx) {
        new_regions->push_back(Region(to_split.llx, to_split.lly,
                    spliter.llx, to_split.ury)); 
        lx = spliter.llx;
    }
    // right region
    if (to_split.urx > spliter.urx) {
        new_regions->push_back(Region(spliter.urx, to_split.lly,
                    to_split.urx, to_split.ury));
        rx = spliter.urx;
    }
    // below
    if (to_split.lly < spliter.lly) {
        new_regions->push_back(Region(lx, to_split.lly,
                    rx, spliter.lly));
    }
    // upon
    if (to_split.ury > spliter.ury) {
        new_regions->push_back(Region(lx, spliter.ury,
                    rx, to_split.ury));
    }
    return new_regions;
}

int main()
{
    int x, y;
    in = fopen(PROG ".in", "r");
    fscanf(in, "%d %d %d", &x, &y, &n);
    colors.push_back(Color(0, 0, x, y, 1));
    for (int i=0; i<n; ++i) {
        int llx, lly, urx, ury, color;
        fscanf(in, "%d %d %d %d %d", &llx, &lly, &urx, &ury, &color);
        colors.push_back(Color(llx, lly, urx, ury, color));
    } 
    fclose(in);
    memset(result, 0, sizeof(result));
    int back_idx = colors.size() - 1;
    result[colors[back_idx].color] = get_size(colors[back_idx].big_region);
    list<Region> regions;
    regions.push_back(colors[back_idx].big_region);
    for (int i=colors.size()-2; i>=0; --i) {
        list<Region> regions_to_split;
        regions_to_split.push_back(colors[i].big_region);
        for (list<Region>::iterator it = regions.begin();
                it != regions.end(); ++it) {
            list<Region>::iterator jt = regions_to_split.begin();
            while (jt != regions_to_split.end()) {
                if (!is_intersect(*it, *jt)) {
                    ++jt;
                    continue;
                }
                auto_ptr<list<Region> > new_regions(split_region(*jt, *it));
                jt = regions_to_split.erase(jt);
                regions_to_split.splice(jt, *new_regions);
            }
        }
        for (list<Region>::iterator it = regions_to_split.begin();
                it != regions_to_split.end(); ++it) {
            result[colors[i].color] += get_size(*it);
        }
        //regions.splice(regions.begin(), regions_to_split);
        regions.push_back(colors[i].big_region);
    }
    out = fopen(PROG ".out", "w");
    for (int i=0; i<MAXN; ++i) {
        if (result[i] == 0)
            continue;
        fprintf(out, "%d %d\n", i, result[i]);
    }
    fclose(out);
    return 0;
}
