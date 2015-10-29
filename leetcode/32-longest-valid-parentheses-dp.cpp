/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

struct Record {
    int begin;
    int end;
    Record(int begin = -1, int end = -1): begin(begin), end(end) {}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        queue<Record> q;
        vector<Record> begins(s.length());
        vector<Record> ends(s.length());
        for (int i=0; i<static_cast<int>(s.length())-1; ++i) {
            if (s[i] == '(' && s[i+1] == ')') {
                Record record(i, i+1);
                q.push(record);
                begins[i] = record;
                ends[i+1] = record;
            }
        }
        int length = 0;
        while (!q.empty()) {
            Record curr = q.front();
            q.pop();
            length = max(curr.end - curr.begin + 1, length);
            if (curr.end + 1 < s.length()
                    && begins[curr.end+1].begin != -1) {
                Record new_record(curr.begin, begins[curr.end+1].end);
                if (update_begin_end(begins, ends, new_record)) {
                    q.push(new_record);
                }
            }
            if (curr.begin > 0 && ends[curr.begin-1].begin != -1) {
                Record new_record(ends[curr.begin-1].begin, curr.end);
                if (update_begin_end(begins, ends, new_record)) {
                    q.push(new_record);
                }
            }
            if (curr.begin > 0 && curr.end < s.length()-1
                    && s[curr.begin-1] == '('
                    && s[curr.end+1] == ')') {
                Record new_record(curr.begin-1, curr.end+1);
                q.push(new_record);
                update_begin_end(begins, ends, new_record);
            }
        }
        return length;
    }
private:
    inline bool update_begin_end(vector<Record> &begins, vector<Record> &ends, const Record &new_record) {
        int length = new_record.end - new_record.begin + 1;
        bool res = false;
        if (begins[new_record.begin].begin == -1
                || begins[new_record.begin].end - begins[new_record.begin].begin + 1 < length) {
            begins[new_record.begin] = new_record;
            res = true;
        }
        if (ends[new_record.end].begin == -1
                || ends[new_record.end].end - ends[new_record.end].begin +1 < length) {
            ends[new_record.end] = new_record;
            res = true;
        }
        return res;
    }
};
