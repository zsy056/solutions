/* 
ID: zsy
LANG: C++
PROG: msquare 
*/
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <queue>
#include <algorithm>

#define PROG "msquare"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define LEN 8

struct status_t {
    string text;
    string path;
};

string target;
set<string> met;

int main()
{
    for (int i=0; i<LEN; ++i) {
        char c;
        in >> c;
        target.push_back(c);
    } 
    met.insert(string("12345678"));
    queue<status_t> sq;
    status_t init;
    init.text = string("12345678");
    sq.push(init);
    status_t currs;
    while (!sq.empty()) {
        currs = sq.front();
        sq.pop();
        if (currs.text == target) {
            break;
        }
        string::iterator beg = currs.text.begin();
        // A
        string a(8, ' ');
        reverse_copy(beg, currs.text.end(), a.begin());
        if (met.find(a) == met.end()) {
            met.insert(a);
            status_t t;
            t.text = a;
            t.path = currs.path + "A";
            sq.push(t);
        }
        // B
        string b(8, ' ');
        rotate_copy(beg, beg + 3, beg + 4, b.begin());
        rotate_copy(beg + 4, beg + 5, currs.text.end(), b.begin() + 4);
        if (met.find(b) == met.end()) {
            met.insert(b);
            status_t t;
            t.text = b;
            t.path = currs.path + "B";
            sq.push(t);
        }
        // C
        string c = currs.text;
        char ac = c[2];
        char bc = c[6];
        c[2] = c[1]; c[6] = c[5];
        c[1] = bc; c[5] = ac;
        if (met.find(c) == met.end()) {
            met.insert(c);
            status_t t;
            t.text = c;
            t.path = currs.path + "C";
            sq.push(t);
        }
    }
    out << currs.path.size() << endl;
    size_t c = 0;
    while (c < currs.path.size()) {
        for (size_t i=0; i<60 && c<currs.path.size(); ++i, ++c) {
            out << currs.path[i];
        } 
        out << endl;
    }
    if (currs.path.size() == 0) {
        out << endl;
    }
    return 0;
}
