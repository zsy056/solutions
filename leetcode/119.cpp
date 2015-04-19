#include <vector>

using namespace std;


class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int> > result(2);
        result[0] = {1};
        for (auto i=1; i<=numRows; ++i) {
            vector<int> row(i+1, 0);
            auto idx = i & 1;
            for (auto j=0; j<i+1; ++j) {
                row[j] = (j==0 || j==i) ? 1 : result[1-idx][j-1] + result[1-idx][j];
            }
            result[idx] = move(row);
        }
        return result[numRows & 1];
    }
};

