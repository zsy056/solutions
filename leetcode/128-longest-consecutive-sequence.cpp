/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> heads;
        unordered_map<int, int> tails;
        for (auto num : nums) {
            auto i = heads.find(num);
            if (i == heads.end()) {
                heads[num] = 1;
                tails[num] = num;
                auto next_head = heads.find(num + 1);
                if (next_head != heads.end()) {
                    tails[num + next_head->second] = num;
                    heads[num] = 1 + next_head->second;
                }
                auto prev_tail = tails.find(num - 1);
                if (prev_tail != tails.end()) {
                    auto prev_head = prev_tail->second;
                    tails[num + heads[num] - 1] = prev_head;
                    heads[prev_head] += heads[num];
                }
            }
        }
        int counter = 0;
        for (auto i : heads) {
            counter = max(counter, i.second);
        }
        return counter;
    }
};
