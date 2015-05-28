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
            auto jmax = static_cast<int>(dissects[i].size() - words.size() + 1);
            for (int j=0; j<jmax; ++j) {
                auto tmp_map = word_map;
                auto flag = false;
                for (int k=j; k<dissects[i].size(); ++k) {
                    auto it = tmp_map.find(dissects[i][k]);
                    if (it == tmp_map.end()) {
                        break;
                    } else {
                        --(it->second);
                    }
                    if (it->second == 0) {
                        tmp_map.erase(it);
                    }
                    if (tmp_map.size() == 0) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    result.push_back(i+j*word_len);
                }
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
    auto is = s.findSubstring("a", {"a"});
    for (auto i : is) {
        cout << i << endl;
    }
    return 0;
}
