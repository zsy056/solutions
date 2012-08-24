/* 
ID: zsy
LANG: C++
PROG: clocks 
*/
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define CLK_NUM 9

ofstream fout("clocks.out");
ifstream fin("clocks.in");

struct stat {
    vector<int8_t> step;
    int clocks;

    stat(): clocks(0) {}

    inline bool isok()
    {
        return clocks==0;
    }

    inline void goe(int pos)
    {
        int tmp = (((clocks >> (pos<<1)) & 3) + 1) & 3;
        tmp = tmp << (pos<<1);
        clocks = (clocks & ~(3 << (pos<<1))) | tmp;
    }

    inline stat go(int choice)
    {
        stat tmp = *this;
        tmp.step.push_back(choice);
        switch (choice) {
        case 1:
            tmp.goe(0);
            tmp.goe(1);
            tmp.goe(3);
            tmp.goe(4);
            break;
        case 2:
            tmp.goe(0);
            tmp.goe(1);
            tmp.goe(2);
            break;
        case 3:
            tmp.goe(1);
            tmp.goe(2);
            tmp.goe(4);
            tmp.goe(5);
            break;
        case 4:
            tmp.goe(0);
            tmp.goe(3);
            tmp.goe(6);
            break;
        case 5:
            tmp.goe(1);
            tmp.goe(3);
            tmp.goe(4);
            tmp.goe(5);
            tmp.goe(7);
            break;
        case 6:
            tmp.goe(2);
            tmp.goe(5);
            tmp.goe(8);
            break;
        case 7:
            tmp.goe(3);
            tmp.goe(4);
            tmp.goe(6);
            tmp.goe(7);
            break;
        case 8:
            tmp.goe(6);
            tmp.goe(7);
            tmp.goe(8);
            break;
        case 9:
            tmp.goe(4);
            tmp.goe(5);
            tmp.goe(7);
            tmp.goe(8);
            break;
        default:
            break;
        }
        return tmp;
    }

    inline void print()
    {
        if (step.size() == 0) 
            return;
        vector<int8_t>::iterator i = step.begin();
        fout << (int)*i;
        while (++i != step.end()) {
            fout << ' ' << (int)*i;
        }
        fout << endl;
    }

    inline void pc()
    {
        for (int i=0; i<CLK_NUM; ++i) {
            cout << ((clocks >> (i<<1)) & 3) << ' ';
        }
        cout << endl;
    }

    inline int next_valid()
    {
        if (step.size() == 0)
            return 0;
        int tmp = step.back();
        if (count(step.begin(), step.end(), tmp) >= 3) {
            return tmp+1;
        } else {
            return tmp;
        }
    }
};

queue<stat> steps;

inline void search()
{
    while (steps.size() > 0) {
        stat tmp = steps.front();
        //tmp.pc();
        steps.pop();
        if (tmp.isok()) {
            tmp.print();
            break;
        }
        for (int i=tmp.next_valid(); i<=9; ++i) {
            steps.push(tmp.go(i));
        }
    }
}

int main()
{
    stat ori;
    for (int i=0; i<CLK_NUM; ++i) {
        int tmp;
        fin >> tmp;
        tmp = tmp % 12 / 3;
        ori.clocks = (ori.clocks & ~(3 << (i<<1))) | (tmp << (i<<1));
    }
    steps.push(ori);
    search();
    return 0;
}
