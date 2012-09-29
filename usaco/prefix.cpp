/* 
ID: zsy
LANG: C++
PROG: prefix 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#define PROG "prefix"

using namespace std;

ofstream fout(PROG ".out");
ifstream fin(PROG ".in");
vector<string> prims;
bool reach[200100];
size_t now = 1;
size_t lmax = 0;
string seq;

int main()
{
    string tmp;
    while (true) {
        fin >> tmp;
        if (tmp == ".") {
            break;
        }
        prims.push_back(tmp);
    }
    while (fin >> tmp) {
        seq.append(tmp);
    }
    memset(reach, false, sizeof(reach));
    reach[0] = true;
    while (now <= seq.length()) {
        //cout << now << endl;
        for (vector<string>::iterator i=prims.begin();
            i!=prims.end() && reach[now-1]; ++i){
            size_t j = 0;
            //cout << *i << endl;
            while (now+j-1<seq.length() && j<i->length() 
                && (*i)[j]==seq[now+j-1]) {
                //cout << (*i)[j] << ' ' << seq[now+j-1] << endl;
                ++j;
            }
            if (j == i->length()) {
                //cout << *i << endl;
                reach[now+j-1] = true;
                if (now+j-1 > lmax) {
                    lmax = now + j - 1;
                }
            }
        }
        ++now;
    }
    //cout << seq.length() << endl;
    fout << lmax << endl;
    return 0;
}
