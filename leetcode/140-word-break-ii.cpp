/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<string, vector<string>> cache;
        return wordBreak(s, wordDict, cache);
    }

private:
    vector<string> wordBreak(
            const string &s,
            const unordered_set<string> &wordDict,
            unordered_map<string, vector<string>> &cache) {
        auto cache_it = cache.find(s);
        if (cache_it != cache.end()) {
            return cache_it->second;
        }
        vector<string> result;
        for (int i=1; i<=s.size(); ++i) {
            auto prefix = s.substr(0, i);
            auto dict_it = wordDict.find(prefix);
            if (dict_it == wordDict.end()) {
                continue;
            }
            if (i < s.size()) {
                auto postfix = s.substr(i);
                auto after = wordBreak(postfix, wordDict, cache);
                for (auto a : after) {
                    result.push_back(prefix + " " + a);
                }
            } else {
                result.push_back(prefix);
            }
        }
        cache[s] = move(result);
        return cache[s];
    }
};
