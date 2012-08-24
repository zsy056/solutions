#include <cstdio>
const int Val[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},
     {-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
int len1,len2,First[102],Second[102],DP[102][102];
int max(int a,int b,int c)
{
  int temp = a > b ? a : b;
 
  return (temp > c ? temp : c);
}
int Index(char ch)
{
 if (ch == 'A') return 0;
 if (ch == 'C') return 1;
 if (ch == 'G') return 2;
 if (ch == 'T') return 3;
 return -1;
}
int Dynamic()
{
 int i,j;
 DP[0][0] = 0;
 for (i=1; i<=len1; i++)  DP[i][0] = DP[i-1][0] + Val[First[i]][4];
 for (i=1; i<=len2; i++)  DP[0][i] = DP[0][i-1] + Val[4][Second[i]];
 for (i=1; i<=len1; i++) {
  for (j=1; j<=len2; j++){
   DP[i][j] = max(DP[i-1][j-1] + Val[First[i]][Second[j]],
       DP[i-1][j] + Val[First[i]][4], DP[i][j-1] + Val[4][Second[j]]);
   printf("%d ", DP[i][j]);
  }
  puts("");
 }
 return DP[len1][len2];
  
}
int main()
{
 int cas,i;
 scanf("%d",&cas);
 char C[102];
 while (cas--)
 {
  scanf("%d %s",&len1,C);
  for (i=1; i<=len1; i++)  First[i] = Index(C[i-1]);
  scanf("%d %s",&len2,C);
  for (i=1; i<=len2; i++)  Second[i] = Index(C[i-1]);
  printf("%d\n",Dynamic());
 }
 return 0;
}
