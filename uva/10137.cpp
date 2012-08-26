#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int in[1002];
int avg;
int rest;
int sum;
int flow;

int main()
{
    while (scanf("%d", &n)==1 && n!=0) {
        sum = 0;
        flow = 0; 
        for (int i=0; i<n; ++i) {
            int h, l;
            scanf("%d.%d", &h, &l); 
            // Attention: wa if using scanf("%f") or even %lf
            in[i] = h*100 + l;
            sum += in[i];
        }
        sort(in, in + n);
        avg = sum/n;
        rest = sum - avg*n;
        for (int i=0; i<n; ++i) {
            if (i < n-rest) {
                int tmp = avg - in[i];
                if (tmp > 0) {
                    flow += tmp;
                }
            } else {
                int tmp = avg + 1 - in[i];
                if (tmp > 0) {
                    flow += tmp;
                }
            }
        }
        
        printf("$%.2f\n", flow/100.0);
    }
    return 0;
}
