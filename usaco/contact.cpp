/* 
ID: zsy
LANG: C++
PROG: contact 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <algorithm>

#define PROG "contact"

using namespace std;

#ifdef DEBUG
ostream& out = cout;
istream& in  = cin;
#else
ofstream out(PROG ".out");
ifstream in(PROG ".in");
#endif

#define LINE_MAX 6

struct Node {
    char c;
    int count;
    Node* children[2];
    Node(char c):
        c(c), count(0)
    {
        children[0] = children[1] = NULL;
    }
};

struct Result {
    int count;
    string seq;
    Result(): count(0) {}
    Result(int count, string seq):
        count(count), seq(seq) {}
};

inline bool operator<(const Result& lv, const Result& rv)
{
    if (lv.count != rv.count) {
        return lv.count > rv.count;
    }
    if (lv.seq.length() != rv.seq.length()) {
        return lv.seq.length() < rv.seq.length();
    }
    return lv.seq < rv.seq;
}

string seq;
int a = 0;
int b = 0;
int n = 0;
Node* root = NULL;
vector<Result> results;

Node* build_tree(int dep, char c)
{
    Node* node = new Node(c);
    if (dep > 1) {
        node->children[0] = build_tree(dep-1, '0');
        node->children[1] = build_tree(dep-1, '1');
    }
    return node;
}

void get_result(int dep, Node* node, const string& path)
{
    if (node == NULL)
        return;
    if (dep >= a && dep <= b)
        results.push_back(Result(node->count, path)); 
    if (dep >= b)
        return;
    get_result(dep + 1, node->children[0], path + '0');
    get_result(dep + 1, node->children[1], path + '1');
}

inline void scan()
{
    for(size_t i=0; i<seq.length(); ++i) {
        Node* tmp_root = root;
        for (int j=0; j<b && i+j<seq.length() && tmp_root!=NULL; ++j) {
            int child_idx = 0;
            switch (seq[i+j]) {
                case '0':
                    child_idx = 0;
                    break;
                case '1':
                    child_idx = 1;
                    break;
                default:
                    break;
            }
            tmp_root = tmp_root->children[child_idx];
            tmp_root->count += 1;
        }
    }
}

int main()
{
    string tmp;
    in >> a >> b >> n;
    while (true) {
        in >> tmp;
        if (in) { 
            seq.append(tmp); 
        } else {
            break;
        }
    }
    // build a binary tree with a height of B + 1 (with a dummy root node)
    root = build_tree(b+1, 0);
    scan();
    get_result(0, root, "");
    sort(results.begin(), results.end());
    int current_count = -1;
    int pattern_count = 0;
    int counter = 0;
    for (size_t i=0; i<results.size(); ) {
        if (current_count != results[i].count) {
            if (counter >= n || results[i].count <= 0)
                break;
            out << results[i].count << endl;
            current_count = results[i].count;
            pattern_count = 0;
            ++counter;
        }
        while (results[i].count == current_count) {
            if (pattern_count == 0) {
                out << results[i].seq;
            } else if (pattern_count < LINE_MAX) {
                out << ' ' << results[i].seq;
            } else {
                pattern_count = 0;
                out << endl << results[i].seq;
            }
            ++pattern_count;
            ++i;
        }
        out << endl;
    }
    return 0;
}
