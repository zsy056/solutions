/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

using pos_t = tuple<int, int>;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited;
        for (int i=0; i<board.size(); ++i) {
            vector<bool> tmp(board[i].size(), false);
            visited.push_back(move(tmp));
        }

        stack<stack<pos_t>> candidates;
        candidates.push(move(get_candidates(board, word[0])));
        if (candidates.top().empty()) {
            return false;
        }
        while (!candidates.empty()) {
            if (candidates.size() == word.length()) {
                return true;
            }
            auto &current = candidates.top();
            while (!current.empty()) {
                auto candidate = current.top();
                int i = get<0>(candidate);
                int j = get<1>(candidate);
                if (visited[i][j]) {
                    visited[i][j] = false;
                    current.pop();
                    continue;
                }
                visited[i][j] = true;
                auto next_char = word[candidates.size()];
                auto next_candidates = get_candidates(board, visited, next_char, candidate);
                if (next_candidates.empty()) {
                    visited[i][j] = false;
                    current.pop();
                } else {
                    candidates.push(move(next_candidates));
                    break;
                }
            }
            if (current.empty()) {
                candidates.pop();
            }
        }
        return false;
    }

private:
    stack<pos_t> get_candidates(const vector<vector<char>> &board, char c) {
        stack<pos_t> candidates;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (c == board[i][j]) {
                    candidates.push(make_tuple(i, j));
                }
            }
        }
        return candidates;
    }

    stack<pos_t> get_candidates(
            const vector<vector<char>> &board,
            const vector<vector<bool>> &visited,
            char c,
            pos_t p) {

        stack<pos_t> candidates;

        int i = get<0>(p);
        int j = get<1>(p);

        if (i > 0 && !visited[i-1][j] && board[i-1][j] == c) {
            candidates.push(make_tuple(i-1, j));
        }
        if (i < board.size()-1 && !visited[i+1][j] && board[i+1][j] == c) {
            candidates.push(make_tuple(i+1, j));
        }
        if (j > 0 && !visited[i][j-1] && board[i][j-1] == c) {
            candidates.push(make_tuple(i, j-1));
        }
        if (j < board[i].size()-1 && !visited[i][j+1] && board[i][j+1] == c) {
            candidates.push(make_tuple(i, j+1));
        }

        return candidates;
    }
};
