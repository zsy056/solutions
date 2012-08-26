#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

int counter = 1;
int m, n;
int field[MAX_NUM+2][MAX_NUM+2];
bool flag = false;

inline void put(int a, int b)
{
    for (int i=a-1; i<=a+1; ++i) {
        for (int j=b-1; j<=b+1; ++j) {
            if (field[i][j] != -1)
                ++field[i][j];
        }
    }
}

int main()
{
    while (scanf("%d %d", &m, &n)==2 && m!=0 && n!=0) {
        if (flag) puts("");
        memset(field, 0, sizeof(field));
        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                char c;
                do {
                    scanf("%c", &c);
                } while (c == '\n');
                if (c == '*') {
                    field[i][j] = -1;
                    put(i, j);
                }
            }
        }
        
        printf("Field #%d:\n", counter++);
        for (int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                if (field[i][j] == -1)
                    printf("%c", '*');
                else
                    printf("%d", field[i][j]);
            }
            puts("");
        }
        flag = true;
    }
    return 0;
}
