/*
   Given a digit string, return all possible letter combinations that the number could represent.

   A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if (digits.length() == 0) {
                return vector<string>();
            }
            if (digits.length() == 1) {
                auto s(mapping[digits[0]]);
                vector<string> result;
                for (int i(0); i<s.length(); ++i) {
                    string ss;
                    ss.push_back(s[i]);
                    result.push_back(ss);
                }
                return result;
            }
            auto results(letterCombinations(digits.substr(1)));
            auto s(mapping[digits[0]]);
            vector<string> finalResults;

            for (int i(0); i<s.length(); ++i) {
                string ss;
                ss.push_back(s[i]);
                for (auto &result : results) {
                    finalResults.push_back(ss + result);
                }
            }
            return finalResults;
        }
    private:
        map<char, string> mapping = {{'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
};
