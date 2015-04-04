#include <cstdio>
#include <cstring>

const static int ORI_LEN = 1000000;
const static int PAR_LEN = 10000;

void whats_next(char *par, int *next, int par_len) {
    next[0] = 0;
    next[1] = 0;
    int i = 1;
    for (auto current=1; current<=par_len+1; ++current) {
        // calculate next[current]
        while (i<=current) {
            if (i == current || par[i] != par[current]) {
                if (i == 0) {
                    next[current+1] = 0;
                    break;
                }
                i = next[i-1];
            } else {
                ++i;
                next[current+1] = i;
                break;
            }
        }
    }
}

int count(char *par, char *ori) {
    int next[PAR_LEN + 2] = { 0 };
    int par_len = strlen(par), ori_len = strlen(ori);
    whats_next(par, next, par_len);

    int i = 0, j = 0;
    int counter = 0;
    while (i<=par_len && j<=ori_len) {
        if (i == par_len) {
            ++counter;
            if (j == ori_len) {
                break;
            }
        }
        if (par[i] != ori[j]) {
            if (i == 0) {
                ++j;
                continue;
            }
            i = next[i];
        } else {
            ++i; ++j;
        }
    }
    return counter;
}


int main()
{
    int n = 0;
    char ori[ORI_LEN + 2] = { 0 };
    char par[PAR_LEN + 2] = { 0 };

    scanf("%d", &n);

    for (auto i=0; i<n; ++i) {
        ori[0] = par[0] = 0;

        scanf("%s", par);
        scanf("%s", ori);
        printf("%d\n", count(par, ori));
    }
    return 0;
}
