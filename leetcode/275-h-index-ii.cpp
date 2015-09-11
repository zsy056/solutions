/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        auto hi = bsearch(citations, 0, n, [n] (int i, const vector<int> &cites) {
            return cites[i] - (n - i);
        });
        auto h = n - hi;
        if (hi >= 0 && citations[hi] - h >= 0) {
            return h;
        }
        return 0;
    }

private:
    // find >= 0
    int bsearch(const vector<int> &nums, int begin, int end, function<int (int, const vector<int>&)> cmp) {
        if (begin == end) {
            return -1;
        }
        if (begin + 1 == end) {
            return begin;
        }
        int mid = (end - begin) / 2 + begin;
        auto mid_res = cmp(mid, nums);
        if (mid_res == 0) {
            return mid;
        } else if (mid_res < 0) {
            return bsearch(nums, mid + 1, end, cmp);
        } else {
            if (mid != 0) {
                auto prev_res = cmp(mid-1, nums);
                if (prev_res == 0) {
                    return mid - 1;
                } else if (prev_res < 0) {
                    return mid;
                }
            }
            return bsearch(nums, begin, mid, cmp);
        }
    }
};

