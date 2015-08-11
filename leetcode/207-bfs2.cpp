/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.
*/

#include <algorithm>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> pre_counters(numCourses, 0);
        for (auto &p : prerequisites) {
            auto course_id = get<0>(p);
            ++pre_counters[course_id];
        }
        queue<int> pres;
        int valid_counter = 0;
        for (int i=0; i<numCourses; ++i) {
            if (pre_counters[i] == 0) {
                pres.push(i);
                ++valid_counter;
            }
        }
        while (!pres.empty()) {
            auto to_remove = pres.front();
            pres.pop();
            for (auto &p : prerequisites) {
                auto course_id = get<0>(p);
                auto dep_course_id = get<1>(p);
                if (dep_course_id == to_remove) {
                    --pre_counters[course_id];
                    if (pre_counters[course_id] == 0) {
                        ++valid_counter;
                        pres.push(course_id);
                    }
                }
            }
        }
        return valid_counter == numCourses;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> p{{1, 0}};
    s.canFinish(2, p);
    return 0;
}
