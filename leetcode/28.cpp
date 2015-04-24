class Solution {
public:
    int strStr(string haystack, string needle) {
        unique_ptr<vector<int> > next(getNext(needle));
        auto i(0), j(0);
        while (i < haystack.length() && j < needle.length()) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
            } else if (j == 0) {
                ++i;
            } else {
                j = (*next)[j];
            }
        }
        return (needle.length() == 0 || j == needle.length()) ?
            i - needle.length() : -1;
    }

private:
    vector<int>* getNext(const string &needle) {
        auto next(new vector<int>(needle.length() + 1, 0));
        for (int current(1), j(0); current < needle.length(); ++current) {
            while (true) {
                if (needle[current] == needle[j]) {
                    ++j;
                    break;
                } else if (j == 0) {
                    break;
                } else {
                    j = (*next)[j];
                }
            }
            (*next)[current+1] = j;
        }
        return next;
    }
};
