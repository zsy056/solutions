#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> score({{'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});

        if (s.empty()) {
            return 0;
        }
        int maxScore(score[s[0]]), maxIdx(0), maxCount(1);
        bool different(false);
        for (auto i=1; i<s.length(); ++i) {
            if (score[s[i]] != maxScore) {
                different = true;
            }
            if (score[s[i]] > maxScore) {
                maxCount = 1;
                maxScore = score[s[i]];
                maxIdx = i;
            }
        }
        for (auto i=maxIdx+1; i<s.length() && s[i]==s[maxIdx]; ++i) {
            ++maxCount;
        }
        int currentScore = maxScore * maxCount;
        if (!different) {
            return currentScore;
        }
        string left = s.substr(0, maxIdx);
        string right = s.substr(maxIdx+maxCount, string::npos);
        return currentScore - romanToInt(left) + romanToInt(right);
    }
};
