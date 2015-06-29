/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> row(n, 0);
        set<int> available;
        for (int i=0; i<n; ++i) {
            available.insert(i);
        }
        int solutions = 0;
        step(row, available, 0, solutions);

        return solutions;
    }

    void step(vector<int> &row, const set<int> &available,
              int next, int &solutions) {
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
                    ++solutions;
                } else {
                    set<int> tmp_available = available;
                    tmp_available.erase(candidate);
                    step(row, tmp_available, next+1, solutions);
                }
            }
        }
    }

};
