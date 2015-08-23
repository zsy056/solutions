/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        int a = get_count(num, 2);
        int b = get_count(num, 3);
        int c = get_count(num, 5);
        return num - pow(2, a) * pow(3, b) * pow(5, c) == 0;
    }

private:
    int get_count(int num, int factor) {
        int counter = 0;
        int mul = factor;
        while (mul <= num && num % mul == 0) {
            ++counter;
            mul *= factor;
        }
        return counter;
    }
};
