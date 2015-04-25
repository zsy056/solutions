/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strings(numRows);
        for (int i(0), current(0), delta(-1); i < s.length(); ++i) {
            strings[current].push_back(s[i]);
            if (current == 0 || current == numRows - 1) {
                delta = numRows == 1 ? 0 : -delta;
            }
            current += delta;
        }
        string result;
        for (auto &s : strings) {
            result.append(s);
        }
        return result;
    }
};

