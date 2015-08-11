/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : end(false)
    {

    }

    TrieNode* find_or_insert(char c) {
        if (children.count(c) == 1) {
            return children[c];
        }
        auto new_node = new TrieNode();
        children[c] = new_node;
        return new_node;
    }

    TrieNode* find(char c) {
        auto it = children.find(c);
        return it == children.end() ? nullptr : it->second;
    }

    void set_end(bool is_end) {
        end = is_end;
    }

    bool is_end() {
        return end;
    }

private:
    bool end;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto current = root;
        for (auto c : word) {
            current = current->find_or_insert(c);
        }
        current->set_end(true);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto current = root;
        for (auto c : word) {
            current = current->find(c);
            if (current == nullptr) {
                return false;
            }
        }
        return current->is_end();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto current = root;
        for (auto c : prefix) {
            current = current->find(c);
            if (current == nullptr) {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
