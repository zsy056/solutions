/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

class Solution {
public:
    bool isNumber(string s) {
        auto trimmed = trim(s);
        return !trimmed.empty()
            && (isAllNumerial(trimmed)
                    || isFloat(trimmed)
                    || isScientific(trimmed));
    }

private:
    bool isAllNumerial(const string &s, bool allowSign = true, bool allowEmpty = false) {
        int idx = 0;
        if (allowSign && s.length() > 0 && (s[0] == '-' || s[0] == '+')) {
            ++idx;
        }
        bool empty = true;
        while (idx < s.length()) {
            if (s[idx] < '0' || s[idx] > '9') {
                return false;
            }
            empty = false;
            ++idx;
        }
        return allowEmpty || !empty;
    }

    bool isFloat(const string &s) {
        int dotIdx = -1;
        int dotCount = 0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '.') {
                dotIdx = i;
                ++dotCount;
            }
            if (dotCount > 1) {
                return false;
            }
        }
        if (dotIdx < 0) {
            return false;
        }
        string p1 = s.substr(0, dotIdx);
        string p2 = s.substr(dotIdx+1, s.length()-dotIdx-1);
        return dotIdx >= 0
            && s.length() > 1
            && isAllNumerial(p1, true, true)
            && isAllNumerial(p2, false, true)
            && (isAllNumerial(p1, true, false) || isAllNumerial(p2, false, false));
    }

    bool isScientific(const string &s) {
        int eIdx = -1;
        int eCount = 0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == 'e') {
                eIdx = i;
                ++eCount;
            }
            if (eCount > 1) {
                return false;
            }
        }
        string p1 = s.substr(0, eIdx);
        string p2 = s.substr(eIdx+1, s.length() - eIdx - 1);
        return eIdx >= 0
            && (isAllNumerial(p1, true) || isFloat(p1))
            && isAllNumerial(p2, true);
    }

    string trim(const string &s) {
        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            ++i;
        }
        int j = s.length() - 1;
        while (j >= 0 && s[j] == ' ') {
            --j;
        }
        if (i > j) {
            return "";
        }
        return s.substr(i, j-i+1);
    }
};
