/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
        auto tokens = getTokens(path);
        auto it = tokens.begin();
        while (it != tokens.end()) {
            if (*it == ".") {
                it = tokens.erase(it);
            } else if (*it == "..") {
                if (it != tokens.begin()) {
                    --it;
                    it = tokens.erase(it);
                }
                it = tokens.erase(it);
            } else {
                ++it;
            }
        }
        return getPath(tokens);
    }
private:
    string getPath(const list<string> &tokens) {
        if (tokens.empty()) {
            return "/";
        }
        string path;
        for (auto s : tokens) {
            path.push_back('/');
            path.append(s);
        }
        return path;
    }

    list<string> getTokens(const string &path) {
        list<string> tokens;
        string current;
        int i = 0;
        while (i < path.length()) {
            if (path[i] == '/' && !current.empty()) {
                tokens.push_back(current);
                current.clear();
            } else if (path[i] != '/') {
                current.push_back(path[i]);
            }
            ++i;
        }
        if (!current.empty()) {
            tokens.push_back(current);
        }
        return tokens;
    }
};
