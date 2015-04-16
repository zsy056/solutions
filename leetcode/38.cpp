#include <string>
#include <sstream>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string result("1");
            while (n > 1) {
                string tmp;
                int current = 0;
                int counter(1);
                while (true) {
                    int i = current + 1;
                    for (; i<result.length() && result[i] == result[current]; ++i) {
                        ++counter;
                    }
                    stringstream ss;
                    ss << counter;
                    tmp.append(ss.str());
                    tmp.push_back(result[current]);
                    current = i;
                    counter = 1;
                    if (current >= result.length()) {
                        break;
                    }
                }
                --n;
                result = tmp;
            }
            return result;
        }
};
