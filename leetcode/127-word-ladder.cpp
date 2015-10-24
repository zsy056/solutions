/*
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<string> current, next;
        int current_dist = 2;
        current.push(beginWord);
        wordDict.erase(beginWord);
        while (!current.empty()) {
            auto s = current.front();
            current.pop();
            for (int i=0; i<s.length(); ++i) {
                for (char c='a'; c<='z'; ++c) {
                    auto candidate = s;
                    candidate[i] = c;
                    if (candidate == endWord) {
                        return current_dist;
                    }
                    auto it = wordDict.find(candidate);
                    if (it == wordDict.end()) {
                        continue;
                    }
                    wordDict.erase(candidate);
                    next.push(candidate);
                }
            }
            if (current.empty()) {
                swap(next, current);
                ++current_dist;
            }
        }
        return 0;
    }

};
