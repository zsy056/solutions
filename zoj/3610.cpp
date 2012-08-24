#include <cstdio>
#include <cstring>

#define STR_LEN 21

char b[STR_LEN];
char g[STR_LEN];
char x[STR_LEN];
int n;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%s %s %s", b, g, x);
        printf("%s will survive\n", g);
    }
    return 0;
}
