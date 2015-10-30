/*
   You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

   For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    public:
        vector<int> findSubstring(string s, const vector<string>& words) {
            unordered_map<uint32_t, int> word_map;
            int word_len = words.size() > 0 ? words[0].length() : 0;
            for (const auto &word : words) {
                auto hash_key = BKDRHash(word);
                auto it = word_map.find(hash_key);
                if (it == word_map.end()) {
                    word_map.insert({hash_key, 1});
                } else {
                    ++(it->second);
                }
            }
            vector<int> result;
            vector<vector<uint32_t>> dissects;
            for (int i=0; i<word_len; ++i) {
                vector<uint32_t> dissect;
                for (int j=0; i+(j+1)*word_len<=s.length(); ++j) {
                    dissect.push_back(BKDRHash(s.substr(i+j*word_len, word_len)));
                }
                dissects.push_back(dissect);
            }
            for (int i=0; i<word_len; ++i) {
                unordered_map<uint32_t, queue<int>> curr_map;
                int begin = 0;
                int end = 0;
                while (end < dissects[i].size()) {
                    auto cit = curr_map.find(dissects[i][end]);
                    auto wit = word_map.find(dissects[i][end]);
                    if (cit == curr_map.end()) {
                        if (wit == word_map.end()) {
                            begin = end + 1;
                        } else {
                            queue<int> q;
                            q.push(end);
                            curr_map.insert({dissects[i][end], q});
                        }
                    } else if (cit->second.size() < wit->second){
                        cit->second.push(end);
                    } else {
                        // clear all invalid
                        while (!cit->second.empty() && cit->second.front() < begin) {
                            cit->second.pop();
                        }
                        if (cit->second.size() >= wit->second) {
                            begin = cit->second.front() + 1;
                            cit->second.pop();
                        }
                        cit->second.push(end);
                    }
                    //cout << i + begin*word_len << ' ' << i + end*word_len << endl;
                    if (end - begin + 1  == words.size()) {
                        result.push_back(i + begin*word_len);
                    }
                    ++end;
                }
            }
            return result;
        }
    private:
        uint32_t BKDRHash(const string &s) {
            uint32_t seed = 131;
            uint32_t hash = 0;
            for (auto c : s) {
                hash = hash * seed + c;
            }
            return hash & 0x7fffffff;
        }
};

int main()
{
    Solution s;
    auto is = s.findSubstring("abababab", {"a","b","a"});
    for (auto i : is) {
        cout << i << endl;
    }
    return 0;
}
