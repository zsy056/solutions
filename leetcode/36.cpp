/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


 * A partially filled sudoku which is valid.

 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

class Solution {
public:
    const static int CELL_HEIGHT = 3;

    const static int CELL_WIDTH = 3;

    bool isValidSudoku(vector<vector<char> > &board) {
        for (auto &row : board) {
            unordered_set<char> presented;
            for (auto c : row) {
                if (!testAndSet(c, &presented)) {
                    return false;
                }
            }
        }
        for (auto i(0); i<board[0].size(); ++i) {
            unordered_set<char> presented;
            for (auto j(0); j<board.size(); ++j) {
                if (!testAndSet(board[j][i], &presented)) {
                    return false;
                }
            }
        }
        for (auto i(0); i < board.size() / CELL_HEIGHT; ++i) {
            for (auto j(0); j < board[0].size() / CELL_WIDTH; ++j) {
                unordered_set<char> presented;
                for (auto k(0); k < CELL_WIDTH * CELL_HEIGHT; ++k) {
                    if (!testAndSet(board[i*CELL_HEIGHT + k/CELL_WIDTH][j*CELL_WIDTH + k%CELL_WIDTH], &presented)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
private:
    bool testAndSet(char c, unordered_set<char> *presented) {
        auto result(false);
        if (c == '.') {
            result = true;
        } else if (presented->find(c) == presented->end()) {
            presented->insert(c);
            result = true;
        }
        return result;
    }
};
