/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
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

    vector<char> get_chars() {
        vector<char> results;
        for (const auto &i : children) {
            results.push_back(i.first);
        }
        return results;
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
    void insert(const string &word) {
        auto current = root;
        for (auto c : word) {
            current = current->find_or_insert(c);
        }
        current->set_end(true);
    }

    // Returns if the word is in the trie.
    bool search(const string &word) {
        auto current = root;
        for (auto c : word) {
            current = current->find(c);
            if (current == nullptr) {
                return false;
            }
        }
        return current->is_end();
    }

    bool search_wildcard(const string &word) {
        search_wildcard(word, 0, root);
    }

    bool search_wildcard(const string &word, int idx, TrieNode *node) {
        if (node == nullptr) {
            return false;
        }
        if (idx == word.length()) {
            return node->is_end();
        }
        if (word[idx] == '.') {
            auto candidates = node->get_chars();
            for (auto c : candidates) {
                auto result = search_wildcard(word, idx + 1, node->find(c));
                if (result) {
                    return true;
                }
            }
            return false;
        }
        auto next = node->find(word[idx]);
        return next == nullptr ? false : search_wildcard(word, idx + 1, next);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(const string &prefix) {
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

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        trie.search_wildcard(word);
    }

private:
    Trie trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
