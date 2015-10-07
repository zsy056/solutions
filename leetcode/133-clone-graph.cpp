/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

using cache_t = unordered_map<int, UndirectedGraphNode*>;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        cache_t cache;
        return cloneGraph(node, cache);
    }
private:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, cache_t &cache) {
        if (node == nullptr) {
            return node;
        }
        auto label = node->label;
        auto it = cache.find(label);
        if (it != cache.end()) {
            return it->second;
        }
        auto new_node = new UndirectedGraphNode(label);
        cache[label] = new_node;
        for (auto neighbor : node->neighbors) {
            new_node->neighbors.push_back(cloneGraph(neighbor, cache));
        }
        return new_node;
    }
};
