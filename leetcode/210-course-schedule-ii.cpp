/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> course_order;
        vector<int> pre_counters(numCourses, 0);
        for (const auto &p : prerequisites) {
            auto course_id = get<0>(p);
            ++pre_counters[course_id];
        }

        queue<int> to_remove;
        for (int i=0; i<numCourses; ++i) {
            if (pre_counters[i] == 0) {
                course_order.push_back(i);
                to_remove.push(i);
            }
        }

        while (!to_remove.empty()) {
            auto course_id = to_remove.front();
            to_remove.pop();
            for (const auto &p : prerequisites) {
                auto current_course_id = get<0>(p);
                auto dep_course_id = get<1>(p);
                if (dep_course_id == course_id) {
                    --pre_counters[current_course_id];
                    if (pre_counters[current_course_id] == 0) {
                        to_remove.push(current_course_id);
                        course_order.push_back(current_course_id);
                    }
                }
            }
        }
        return course_order.size() == numCourses ? course_order : vector<int>{};
    }
};
