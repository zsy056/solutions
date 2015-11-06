/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int middle((nums1.size() + nums2.size()) / 2);
        if (((nums1.size() + nums2.size()) & 1) == 1) {
            return findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), middle);
        } else {
            auto m1(findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), middle));
            auto m2(findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), middle - 1));
            return (m1 + m2) / 2;
        }
    }

    double findKth(const vector<int> &nums1, int begin1, int end1,
            const vector<int> &nums2, int begin2, int end2,
            int k) {
        if (begin1 >= end1) {
            return nums2[begin2 + k];
        }
        if (begin2 >= end2) {
            return nums1[begin1 + k];
        }
        if (k == 0) {
            return min(nums1[begin1], nums2[begin2]);
        }
        int middleOffset((end1 - begin1 - 1) / 2);
        // !!
        middleOffset = middleOffset >= k ? k - 1 : middleOffset;
        int idx1(begin1 + middleOffset);
        int idx2(begin2 + k - middleOffset - 1);
        if (nums1[idx1] == nums2[idx2]) {
            return nums1[idx1];
        }
        if (nums1[idx1] < nums2[idx2]) {
            return findKth(nums1, idx1+1, end1, nums2, begin2, idx2+1, k-(idx1-begin1)-1);
        }
        if (nums1[idx1] > nums2[idx2]) {
            return findKth(nums1, begin1, idx1+1, nums2, idx2+1, end2, k-(idx2-begin2)-1);
        }
        return 0;
    }
};

int main()
{
    Solution s;
    cout << s.findMedianSortedArrays(vector<int>({1, 3}), vector<int>({2})) << endl;
    return 0;
}
