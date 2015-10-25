/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

using pos_t = tuple<int, int>;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return;
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'Y';
                }
            }
        }
        for (int i=0; i<n; ++i) {
            if (board[i][0] == 'Y') {
                flooding(i, 0, board);
            }
            if (board[i][board[i].size()-1] == 'Y') {
                flooding(i, board[i].size()-1, board);
            }
        }
        for (int i=0; i<board[0].size(); ++i) {
            if (board[0][i] == 'Y') {
                flooding(0, i, board);
            }
            if (board[n-1][i] == 'Y') {
                flooding(n-1, i, board);
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void flooding(int i, int j, vector<vector<char>> &board) {
        queue<pos_t> q;
        q.push(make_tuple(i, j));
        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            auto ci = get<0>(c);
            auto cj = get<1>(c);
            if (board[ci][cj] != 'Y') {
                continue;
            }
            board[ci][cj] = 'O';
            int m = board.size();
            int n = board[i].size();
            if (ci > 0) {
                q.push(make_tuple(ci-1, cj));
            }
            if (ci < m-1) {
                q.push(make_tuple(ci+1, cj));
            }
            if (cj > 0) {
                q.push(make_tuple(ci, cj-1));
            }
            if (cj < n-1) {
                q.push(make_tuple(ci, cj+1));
            }
        }
    }
};
