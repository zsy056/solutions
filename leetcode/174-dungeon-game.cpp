#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static const uint8_t LEFT = 2;
    static const uint8_t UP = 1;
    static const uint8_t BOTH = 3;
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if (m == 0) {
            return 0;
        }
        int n = dungeon[0].size(); 
        if (n == 0) {
            return 0;
        }
        int **init_health = new int*[m];
        for (auto i=0; i<m; ++i) {
            init_health[i] = new int[n];
        }
        init_health[m-1][n-1] = (dungeon[m-1][n-1] >= 0) ?
                                1 : 1 - dungeon[m-1][n-1]; 
        for (auto i=m-1; i>=0; --i) {
            for (auto j=n-1; j>=0; --j) {
                int tmp_init = INT_MAX;
                if (i+1 < m) {
                    tmp_init = init_health[i+1][j] - dungeon[i][j];
                    tmp_init = (tmp_init <= 0) ? 1 : tmp_init;
                }
                if (j+1 < n && tmp_init > init_health[i][j+1] - dungeon[i][j]) {
                    tmp_init = init_health[i][j+1] - dungeon[i][j];
                    tmp_init = (tmp_init <= 0) ? 1 : tmp_init;
                }
                if (tmp_init == INT_MAX) {
                    continue;
                }
                init_health[i][j] = tmp_init;
            }
        }
        return init_health[0][0];
    }
};

