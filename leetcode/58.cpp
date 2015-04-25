/*
   Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

   If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto begin(false);
        auto counter(0);
        for (int i(s.length() - 1); i >= 0; --i) {
            if (!begin && s[i] == ' ') {
                continue;
            } else if (s[i] == ' ') {
                break;
            } else {
                begin = true;
                ++counter;
            }
        }
        return counter;
    }
};
