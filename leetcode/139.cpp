#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

struct Trie {
    unordered_map<char, Trie*> children;
    bool has;
    Trie(): children(), has(false) {}
    ~Trie() {
        for (auto& it : children) {
            delete it.second;
        }
    }
};

class Solution {
    public:
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            Trie* trie = new Trie();
            for (auto &word : wordDict) {
                auto current = trie;
                for (auto i=0; i<word.length(); ++i) {
                    auto it = current->children.find(word[i]);
                    if (it == current->children.end()) {
                        current->children.insert({word[i], new Trie()});
                        it = current->children.find(word[i]);
                    }
                    current = it->second;
                    if (i == word.length() - 1) {
                        current->has = true;
                    }
                }
            }
            int current_idx = 0;
            stack<int> pos;
            auto current = trie;
            unordered_set<int> unable;
            auto current_begin = 0;
            while (true) {
                auto it = current->children.find(s[current_idx]);
                if (it == current->children.end()) {
                    if (pos.empty()) {
                        return false;
                    }
                    current_idx = nextBegin(&unable, &pos, current_begin);
                    if (current_idx == -1) {
                        break;
                    }
                    current = trie;
                    current_begin = current_idx;
                } else {
                    current = it->second;
                    if (current->has) {
                        pos.push(current_idx);
                    }
                    ++current_idx;
                }
                if (current_idx == s.length()) {
                    if (pos.top() == s.length() - 1) {
                        break;
                    }
                    current_idx = nextBegin(&unable, &pos, current_begin);
                    if (current_idx == -1) {
                        break;
                    }
                    current = trie;
                    current_begin = current_idx;
                }
            }
            bool result = (!pos.empty() && pos.top() == s.length()-1) ? true : false;
            delete trie;
            return result;
        }
    private:
        int nextBegin(unordered_set<int> *unable, stack<int> *matched, int current_begin) {
            unable->insert(current_begin);
            while (!matched->empty() && unable->find(matched->top() + 1) != unable->end()) {
                matched->pop();
            }
            if (matched->empty()) {
                return -1;
            }
            return matched->top() + 1;
        }
};


int main()
{
    //unordered_set<string> dict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
    //string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    unordered_set<string> dict({"a","b","bbb","bbbb"});
    string s("bb");
    Solution so;
    cout << so.wordBreak(s, dict) << endl;
    return 0;
}
