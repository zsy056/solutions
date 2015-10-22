#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<uint8_t> converted;
        convert(s, converted);
        vector<uint32_t> codes;
        to_code(converted, codes);
        unordered_map<uint32_t, uint32_t> counter;
        for (auto code : codes) {
            auto it = counter.find(code);
            if (it == counter.end()) {
                counter[code] = 1;
            } else {
                ++(it->second);
            }
        }
        vector<string> result;
        for (auto i=0; i<codes.size(); ++i) {
            auto it = counter.find(codes[i]);
            if (it != counter.end() && it->second > 1) {
                result.push_back(s.substr(i, 10)); 
                counter.erase(it);
            }
        }
        return result;
    }
private:
    static void to_code(const vector<uint8_t> &src, vector<uint32_t> &dst) {
        if (src.size() < 10) {
            return;
        }
        for (auto i=0; i<=src.size()-10; ++i) {
            int code = 0;
            for (auto j=0; j<10; ++j) {
                code = (code << 2) | src[i+j]; 
            }
            dst.push_back(code);
        }   
    }

    static void convert(const string &s, vector<uint8_t> &out) {
        for (auto c : s) {
            uint8_t a = 0;
            switch (c) {
                case 'A':
                    a = 0;
                    break;
                case 'C':
                    a = 1;
                    break;
                case 'G':
                    a = 2;
                    break;
                case 'T':
                    a = 3;
                    break;
                default:
                    break;
            }
            out.push_back(a);
        }
    }
};
