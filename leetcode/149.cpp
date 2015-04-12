#include <vector>
#include <map>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Line {
    double k;
    int b;
    int x;
    bool x_valid;
    Line(): k(0), b(0), x(0), x_valid(false) {}
    Line(double k, int b, int x, bool x_valid): k(k), b(b), x(x), x_valid(x_valid) {}
};

bool operator<(const Line &lv, const Line &rv) {
    if (!lv.x_valid && !rv.x_valid) {
        return lv.k < rv.k || (lv.k == rv.k && lv.b < rv.b);
    } else if (lv.x_valid && rv.x_valid) {
        return lv.x < rv.x;
    } else {
        return lv.x_valid;
    }
}

struct Recorder {
    unordered_set<int> points;
    Recorder(): points() {}
    Recorder(int p1, int p2): points({p1, p2}) {}
    void add(int p1, int p2) {
        points.insert(p1);
        points.insert(p2);
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        vector<vector<int> > mat(points.size());
        map<Line, Recorder> counters;
        if (points.empty()) {
            return 0;
        }
        for (auto i=0; i<points.size(); ++i) {
            for (auto j=0; j<i; ++j) {
                auto delta_x = points[i].x - points[j].x;
                Line line;
                if (delta_x == 0) {
                    line = Line(0, 0, points[i].x, true);
                } else {
                    double k = (points[i].y - points[j].y) * 1.0 / delta_x;
                    auto b = (points[i].x*points[j].y - points[j].x*points[i].y) / delta_x;
                    line = Line(k, b, 0, false);
                }
                auto it = counters.find(line);
                if (it == counters.end()) {
                    counters[line] = Recorder(i, j);
                } else {
                    it->second.add(i, j);
                }
            }
        }
        int max = 1;
        for (auto i=counters.begin(); i!=counters.end(); ++i) {
            if (i->second.points.size() > max) {
                max = i->second.points.size();
            }
        }
        return max;
    }
};
