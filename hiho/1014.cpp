#include <cstdio>
#include <cstring>
#include <unordered_map>

using namespace std;

struct Node {
    uint32_t count;
    unordered_map<char, Node*> children;
    Node(): count(1) {}
};

struct Trie {
    unordered_map<char, Node*> trie;

    void add(const char *str) {
        auto len = strlen(str);
        auto current_trie = &trie;
        for (auto i=0; i<len; ++i) {
            auto it = current_trie->find(str[i]);
            if (it == current_trie->end()) {
                current_trie->insert({str[i], new Node()});
                current_trie = &((*current_trie)[str[i]]->children);
            } else {
                ++(it->second->count);
                current_trie = &(it->second->children);
            }
        }
    }

    uint32_t count(const char *str) const {
        auto len = strlen(str);
        auto current_trie = &trie;
        for (auto i=0; i<len; ++i) {
            auto it = current_trie->find(str[i]);
            if (it == current_trie->end()) {
                return 0;
            } else if (i == len-1) {
                return it->second->count;
            } else {
                current_trie = &(it->second->children);
            }
        }
        return 0;
    }
};

int main()
{
    int n = 0, m = 0;
    Trie trie;
    scanf("%d", &n);
    for (auto i=0; i<n; ++i) {
        char tmp[11] = { 0 };
        scanf("%s", tmp);
        trie.add(tmp);
    }
    scanf("%d", &m);
    for (auto i=0; i<n; ++i) {
        char tmp[11] = { 0 };
        scanf("%s", tmp);
        printf("%d\n", trie.count(tmp));
    }
    return 0;
}
