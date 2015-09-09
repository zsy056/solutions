/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

class Solution {
public:
    string numberToWords(int num) {
        for (auto &tp : S3) {
            auto level = get<0>(tp);
            auto word = get<1>(tp);
            auto left = num / level;
            auto right = num % level;
            if (left == 0) {
                continue;
            }
            auto left_str = numberToWords(left);
            auto right_str = numberToWords(right);
            return left_str + " " + word + (right_str == "Zero" ? "" : " " + right_str);
        }
        auto left = num / 10;
        auto right = num % 10;
        if (left <= 1) {
            return S1[num];
        }
        return S2[left] + (right == 0 ? "" : " " + S1[right]);
    }

private:
    vector<string> S1 { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    unordered_map<int, string> S2 { {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };
    vector<pair<int, string>> S3 { {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"} };
};
