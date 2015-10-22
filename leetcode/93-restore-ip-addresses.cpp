/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        vector<string> tmp;
        restore(s, 0, tmp, results);
        return results;
    }

private:
    void restore(
            const string &s,
            int b,
            vector<string> &current,
            vector<string> &result) {

        if (current.size() == 4 && s.length() == b) {
            result.push_back(ip2s(current));
            return;
        } else if (current.size() == 4 || s.length() == b) {
            return;
        }

        for (int i=0; i<3 && b+i<s.length(); ++i) {
            auto sub = s.substr(b, i+1);
            if (valid(s.substr(b, i+1))) {
                current.push_back(sub);
                restore(s, b+i+1, current, result);
                current.pop_back();
            }
        }

    }

    bool valid(const string &s)
    {
        if (s.length() == 3) {
            return s[0] == '1'
                || (s[0] == '2'
                        && ((s[1] == '5' && s[2] <= '5')
                                || s[1] <= '4'));
        }
        return s.length() == 1 || s[0] != '0';
    }

    string ip2s(const vector<string> &ip)
    {
        return ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
    }
};
