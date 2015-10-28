/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct EndPoint {
    int value;
    bool start;
    int end;
    EndPoint() : value(0), start(false), end(0) {}
    EndPoint(int value, bool start, int end):
        value(value), start(start), end(end) {}
};

bool operator<(const EndPoint &lv, const EndPoint &rv) {
    if (lv.value == rv.value) {
        return lv.start && !rv.start;
    }
    return lv.value < rv.value;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<EndPoint> end_points;
        for (auto &interval : intervals) {
            EndPoint start(interval.start, true, interval.end);
            EndPoint end(interval.end, false, interval.end);
            end_points.push_back(start);
            end_points.push_back(end);
        }
        sort(end_points.begin(), end_points.end());
        vector<Interval> rets;
        int current_start = 0;
        int current_end = 0;
        bool in_range = false;
        for (auto &end_point : end_points) {
            if (!in_range && end_point.start) {
                in_range = true;
                current_start = end_point.value;
                current_end = end_point.end;
            } else if (in_range) {
                if (!end_point.start && end_point.value == current_end) {
                    in_range = false;
                    Interval range(current_start, current_end);
                    rets.push_back(range);
                } else if (end_point.start) {
                    current_end = max(current_end, end_point.end);
                }
            }
        }
        return rets;
    }
};
