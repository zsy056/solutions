#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 102

const int stab[5][5] = { { 5, -1, -2. -1, -3},
                   {-1,  5, -3, -2, -4},
                   {-2, -3,  5, -2, -2},
                   {-1, -2, -2,  5, -1},
                   {-3, -4, -2, -1, 0}};

int n = 0;

char c1[MAX];
int in1[MAX];
int len1;
char c2[MAX];
int in2[MAX];
int len2;
int re[MAX][MAX];

inline int tmax(int a, int b, int c)
{
    return max(max(a, b), c);
}

inline int smax()
{
    re[0][0] = 0;
    for(int i=1; i<=len1; ++i) {
        re[i][0] = re[i-1][0] + stab[in1[i]][4];
    }
    for(int i=1; i<=len2; ++i) {
        re[0][i] = re[0][i-1] + stab[4][in2[i]];
    }
    for(int i=1; i<=len1; ++i) {
        for(int j=1; j<=len2; ++j) {
            int s1 = re[i-1][j-1] + stab[in1[i]][in2[j]];
            int s2 = re[i][j-1] + stab[4][in2[j]];
            int s3 = re[i-1][j] + stab[in1[i]][4];
            re[i][j] = tmax(s1, s2, s3);
        }
    }
    return re[len1][len2];
}

inline void conv(char* ch, int* in, int len)
{
    for(int i=1; i<=len; ++i){
        switch(ch[i-1]) {
        case 'A':
            in[i] = 0;
            break;
        case 'C':
            in[i] = 1;
            break;
        case 'G':
            in[i] = 2;
            break;
        case 'T':
            in[i] = 3;
            break;
        default:
            break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d %s", &len1, c1);
        scanf("%d %s", &len2, c2);
        conv(c1, in1, len1);
        conv(c2, in2, len2);
        printf("%d\n", smax());
    }
    return 0;
}
