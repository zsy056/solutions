#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 17

vector<int> digits;
vector<int> bases;

inline void conv(int n, int base)
{
    while(n>0) {
        digits.push_back(n%base);
        n /= base;
    }
}

inline bool is_pal()
{
    for(size_t i=0; i<digits.size()/2; ++i){
        if(digits[i]!=digits[digits.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    while(true){
        int n;
        scanf("%d", &n);
        if(n == 0) break;
        for(int i=2; i<MAX_N; ++i){
            conv(n, i); 
            if(is_pal()) bases.push_back(i);
            digits.clear();
        }
        if(bases.size()==0){
            printf("Number %d is not a palindrom\n", n);
        } else {
            printf("Number %d is palindrom in basis", n);
            for(vector<int>::iterator i=bases.begin(); i!=bases.end(); ++i){
                printf(" %d", *i);
            }
            puts("");
        }
        bases.clear();
    }
    return 0;
}
