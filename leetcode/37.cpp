/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>


using namespace std;

using current_t = vector<unordered_set<char>>;
using board_t = vector<vector<char>>;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        current_t rows(9), cols(9), blocks(9);
        int count = 0;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    ++count;
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    blocks[i/3*3 + j/3].insert(board[i][j]);
                }
            }
        }
        doSolveSudoku(board, count, rows, cols, blocks);
    }
private:
    bool doSolveSudoku(board_t &board, int count,
            current_t &rows, current_t &cols, current_t &blocks) {
        if (count == 81) {
            return true;
        }
        int row_to_fill = -1;
        int col_to_fill = -1;
        int num_candidates = INT_MAX;
        shared_ptr<vector<char>> candidtes;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                shared_ptr<vector<char>> tmp_candidates(new vector<char>());
                for (char c = '1'; c<='9'; ++c) {
                    if (tmp_candidates->size() >= num_candidates) {
                        break;
                    }
                    if (rows[i].count(c) == 0
                            && cols[j].count(c) == 0
                            && blocks[i/3*3+j/3].count(c) == 0){
                        tmp_candidates->push_back(c);
                    }
                }
                if (tmp_candidates->size() == 0) {
                    return false;
                }
                if (tmp_candidates->size() < num_candidates) {
                    candidtes = tmp_candidates;
                    num_candidates = tmp_candidates->size();
                    row_to_fill = i;
                    col_to_fill = j;
                }
            }
        }
        for (auto c : *candidtes) {
            board[row_to_fill][col_to_fill] = c;
            rows[row_to_fill].insert(c);
            cols[col_to_fill].insert(c);
            blocks[row_to_fill/3*3 + col_to_fill/3].insert(c);
            auto success = doSolveSudoku(board, count + 1,
                    rows, cols, blocks);
            if (success) {
                return true;
            }
            board[row_to_fill][col_to_fill] = '.';
            rows[row_to_fill].erase(c);
            cols[col_to_fill].erase(c);
            blocks[row_to_fill/3*3 + col_to_fill/3].erase(c);
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<string> src{"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    board_t board;
    for (const auto & s : src) {
        vector<char> cs;
        for (auto c : s) {
            cs.push_back(c);
        }
        board.push_back(move(cs));
    }
    s.solveSudoku(board);
    for (const auto &row : board) {
        for (auto c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0;
}
