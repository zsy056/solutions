/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> row(n, 0);
        set<int> available;
        for (int i=0; i<n; ++i) {
            available.insert(i);
        }
        vector<vector<int>> solutions;
        step(row, available, 0, solutions);
        vector<vector<string>> results;
        string line(n, '.');
        for (auto& solution : solutions) {
            vector<string> result;
            for (auto i : solution) {
                auto tmp = line;
                tmp[i] = 'Q';
                result.push_back(move(tmp));
            }
            results.push_back(move(result));
        }
        return results;
    }

    void step(vector<int> &row, const set<int> &available,
              int next, vector<vector<int>> &solutions) {
        if (next >= row.size()) {
            return;
        }
        for (auto candidate : available) {
            auto variable = true;
            for (auto j = 0; j < next; ++j) {
                if (next - j == abs(candidate - row[j])) {
                    variable = false;
                    break;
                }
            }
            if (variable) {
                row[next] = candidate;
                if (next + 1 == row.size()) {
                    solutions.push_back(row);
                } else {
                    set<int> tmp_available = available;
                    tmp_available.erase(candidate);
                    step(row, tmp_available, next+1, solutions);
                }
            }
        }
    }
};
