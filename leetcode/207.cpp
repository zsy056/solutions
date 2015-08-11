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

struct Course {
    int idx;
    unordered_set<int> deps;
};

bool cmp(int a, int b, const vector<Course> &graph)
{
    return graph[a].deps.size() > graph[b].deps.size();
}

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Course> graph(numCourses);
        vector<Course> reverse(numCourses);
        vector<int> course_idxes(numCourses);
        for (int i=0; i<numCourses; ++i) {
            course_idxes[i] = i;
        }
        for (auto p : prerequisites) {
            auto course = get<0>(p);
            auto dependent_course = get<1>(p);
            graph[course].deps.insert(dependent_course);
            reverse[dependent_course].deps.insert(course);
        }
        make_heap(course_idxes.begin(), course_idxes.end(), [&graph] (int a, int b) {
            return cmp(a, b, graph);
        });
        while (!course_idxes.empty()) {
            pop_heap(course_idxes.begin(), course_idxes.end());
            auto course_id = course_idxes.back();
            if (!graph[course_id].deps.empty()) {
                return false;
            }
            course_idxes.pop_back();
            for (auto &i : reverse[course_id].deps) {
                graph[i].deps.erase(course_id);
            }
            make_heap(course_idxes.begin(), course_idxes.end(), [&graph] (int a, int b) {
                return cmp(a, b, graph);
            });
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> p{{1, 0}};
    s.canFinish(2, p);
    return 0;
}
