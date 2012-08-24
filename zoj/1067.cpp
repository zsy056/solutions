#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

struct Color {
    int r;
    int g;
    int b;
};

#define MAX 16

inline int squar(int a)
{
    return a * a;
}

Color color[MAX];

int main()
{
    int a, b, c;
    for(int i=0; i<16; ++i) {
        scanf("%d %d %d", &(color[i].r), &(color[i].g), &(color[i].b));
    }
    while(true){
        scanf("%d %d %d", &a, &b, &c);
        if(a==-1 && b==-1 && c==-1) break;
        int min = 255*255*3+1, idx = -1;
        for(int j=0; j<16; ++j) {
            int dist = squar(a-color[j].r) + squar(b-color[j].g)
                + squar(c-color[j].b);
            if(dist==0) {
                idx = j;
                break;
            }
            if(min > dist) {
                min = dist;
                idx = j;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", a, b, c,
            color[idx].r, color[idx].g, color[idx].b);
    }
    return 0;
}
