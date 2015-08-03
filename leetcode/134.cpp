/*
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> partial(n, 0);
        for (int i=0; i<n; ++i) {
            partial[i] = gas[i] - cost[i];
        }
        int counter = 0;
        int max_counter = 0;
        vector<int> begin_idx;
        int current_begin = -1;
        bool cycled = false;
        for (int i=0; i<n; ++i) {
            if (i == current_begin) {
                break;
            }
            if (partial[i] >= 0) {
                if (current_begin == -1) {
                    current_begin = i;
                }
                ++counter;
                if (counter == max_counter) {
                    begin_idx.push_back(current_begin);
                } else if (counter > max_counter) {
                    if (begin_idx.empty() || current_begin != begin_idx.back()) {
                        begin_idx.clear();
                        begin_idx.push_back(current_begin);
                    }
                    max_counter = counter;
                }
                if (i == n-1 && !cycled) {
                    cycled = true;
                    i = -1;
                }
            } else {
                counter = 0;
                current_begin = -1;
                if (cycled) {
                    break;
                }
            }
        }
        for (auto begin : begin_idx) {
            if (can_cycle(gas, cost, begin)) {
                return begin;
            }
        }
        return -1;
    }
private:
    inline bool can_cycle(
            const vector<int> &gas,
            const vector<int> &cost,
            int begin) {
        int n = gas.size();
        int current_gas = gas[begin] - cost[begin];
        for (int i=begin+1; ; ++i) {
            i = i % n;
            if (i == begin) {
                break;
            }
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {
                return false;
            }
        }
        return true;
    }
};
