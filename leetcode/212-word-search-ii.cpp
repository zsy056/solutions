/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

struct TrieNode {
    TrieNode(char c, bool end): c(c), end(end) {}
    char c;
    bool end;
    unordered_map<char, shared_ptr<TrieNode>> next;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto root = make_shared<TrieNode>(0, false);
        for (auto &w : words) {
            auto current = root;
            int n = w.length();
            for (int i=0; i<n; ++i) {
                auto next_it = current->next.find(w[i]);
                if (next_it == current->next.end()) {
                    auto next_node = make_shared<TrieNode>(w[i], i==n-1);
                    current->next[w[i]] = next_node;
                    current = next_node;
                } else {
                    next_it->second->end |= i==n-1;
                    current = next_it->second;
                }
            }
        }
        string current;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_set<string> result;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                traverse(board, visited, i, j, m, n, root, current, result);
            }
        }
        vector<string> v;
        for (auto &s : result) {
            v.push_back(move(s));
        }
        return v;
    }

private:
    void traverse(
            const vector<vector<char>> &board,
            vector<vector<bool>> &visited,
            int i, int j,
            int m, int n,
            const shared_ptr<TrieNode> &current,
            string &word,
            unordered_set<string> &result) {
        if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || current == nullptr) {
            return;
        }
        auto it = current->next.find(board[i][j]);
        if (it != current->next.end()) {
            auto next = it->second;
            visited[i][j] = true;
            word.push_back(board[i][j]);
            if (next->end) {
                result.insert(word);
            }
            traverse(board, visited, i+1, j, m, n, next, word, result);
            traverse(board, visited, i-1, j, m, n, next, word, result);
            traverse(board, visited, i, j+1, m, n, next, word, result);
            traverse(board, visited, i, j-1, m, n, next, word, result);
            word.pop_back();
            visited[i][j] = false;
        }
    }
};
