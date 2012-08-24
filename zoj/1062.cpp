#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAX 18

long tab[MAX];

template<unsigned int N>
struct Ref {
    enum { VALUE = 2*(N-1)/(N+1) * Ref<N-1>::VALUE };
    static void fill()
    {
        Ref<N-1>::fill();
        tab[N] = VALUE;
    }
};

template<>
struct Ref<1> {
    enum { VALUE = 1 };
    static void fill()
    {
        tab[1] = 1;
    }
};

inline void get_tree(int n)
{
        
}

int main()
{
    int n;
    Ref<18>::fill();
    for(int i=0; i<18; ++i){
        printf("%ld\n", tab[i]);
    }
    //while(true){
    //    scanf("%d", &n);
    //    if(n == 0) break;
    //    get_tree(n);
    //}
    return 0;
}
