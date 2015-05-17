/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        if (num <= 0) {
            return "";
        }
        string result;
        if (num >= 900) {
            return string(num >= 1000 ? "" : "C")
                + "M"
                + intToRoman(num >= 1000 ? num-1000 : num+100-1000);
        }
        if (num >= 400) {
            return string(num >= 500 ? "" : "C")
                + "D"
                + intToRoman(num >= 500 ? num-500 : num+100-500);
        }
        if (num >= 90) {
            return string(num >= 100 ? "" : "X")
                + "C"
                + intToRoman(num >= 100 ? num-100 : num+10-100);
        }
        if (num >= 40) {
            return string(num >= 50 ? "" : "X")
                + "L"
                + intToRoman(num >= 50 ? num-50 : num+10-50);
        }
        if (num >= 9) {
            return string(num >= 10 ? "" : "I")
                + "X"
                + intToRoman(num >= 10 ? num-10 : num+1-10);
        }
        if (num >= 4) {
            return string(num >= 5 ? "" : "I")
                + "V"
                + intToRoman(num >= 5 ? num-5 : num+1-5);
        }
        return "I" + intToRoman(num-1);
    }
};
