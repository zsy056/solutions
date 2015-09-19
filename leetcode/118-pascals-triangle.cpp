#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result(numRows);
        if (numRows != 0) {
            result[0] = {1};
        }
        for (auto i=1; i<numRows; ++i) {
            vector<int> row(i+1, 0);
            for (auto j=0; j<i+1; ++j) {
                row[j] = (j==0 || j==i) ? 1 : result[i-1][j-1] + result[i-1][j];
            }
            result[i] = move(row);
        }
        return result;
    }
};
