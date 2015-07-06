/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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

bool operator<(const Interval &lv, const Interval &rv)
{
    return lv.start < rv.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        Interval merged(INT_MIN, INT_MIN);
        auto inInterval = false;
        auto exceed = false;
        for (int i=0; i<intervals.size(); ++i) {
            if (!inInterval
                    && intervals[i].start <= newInterval.end
                    && intervals[i].end >= newInterval.start) {
                inInterval = true;
                merged.start = min(intervals[i].start, newInterval.start);
                merged.end = max(intervals[i].end, newInterval.end);
            } else if (inInterval && intervals[i].start > newInterval.end) {
                inInterval = false;
                exceed = true;
                result.push_back(merged);
                result.push_back(intervals[i]);
            } else if (inInterval) {
                merged.end = max(intervals[i].end, merged.end);
            } else if (!inInterval) {
                if (!exceed && intervals[i].start > newInterval.end) {
                    exceed = true;
                    result.push_back(newInterval);
                }
                result.push_back(intervals[i]);
            }
        }
        if (inInterval) {
            result.push_back(merged);
        }
        if (!exceed && !inInterval) {
            result.push_back(newInterval);
        }

        return result;
    }
};
