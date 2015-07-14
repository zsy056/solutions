/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroEnd = 0;
        int oneEnd = 0;
        int twoBegin = nums.size() - 1;
        while (twoBegin >= oneEnd && nums[twoBegin] == 2) {
            --twoBegin;
        }
        while (oneEnd <= twoBegin) {
            switch (nums[oneEnd]) {
            case 0:
                nums[zeroEnd] = 0;
                if (zeroEnd < oneEnd) {
                    nums[oneEnd] = 1;
                }
                ++oneEnd;
                ++zeroEnd;
                break;
            case 1:
                ++oneEnd;
                break;
            case 2:
                swap(nums[twoBegin], nums[oneEnd]);
                while (twoBegin >= oneEnd && nums[twoBegin] == 2) {
                    --twoBegin;
                }
                break;
            default:
                break;
            }
        }
    }
};
