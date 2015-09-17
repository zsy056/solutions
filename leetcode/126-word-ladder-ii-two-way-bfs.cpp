/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_map<string, vector<string>> next;
        vector<vector<string>> paths;
        if (get_next(beginWord, endWord, wordList, next)) {
            vector<string> path {beginWord};
            get_path(beginWord, endWord, next, path, paths);
        }
        return paths;
    }

private:
    bool get_next(
            const string &beginWord,
            const string &endWord,
            unordered_set<string> &wordList,
            unordered_map<string, vector<string>> &next) {

        unordered_set<string> head {beginWord};
        unordered_set<string> tail {endWord};
        wordList.erase(beginWord);
        wordList.erase(endWord);
        auto is_head = true;
        int n = beginWord.length();
        auto long_enough = false;
        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                swap(head, tail);
                is_head = !is_head;
            }
            unordered_set<string> next_head;
            for (auto &current : head) {
                string current_copy = current;
                for (int i=0; i<n; ++i) {
                    auto original = current[i];
                    for (auto c='a'; c<='z'; ++c) {
                        if (c == original) {
                            continue;
                        }
                        current_copy[i] = c;
                        auto tail_it = tail.find(current_copy);
                        if (tail_it != tail.end()) {
                            long_enough = true;
                            is_head ? next[current].push_back(current_copy) : next[current_copy].push_back(current);
                        } else if (!long_enough && wordList.count(current_copy) == 1) {
                            is_head ? next[current].push_back(current_copy) : next[current_copy].push_back(current);
                            next_head.insert(current_copy);
                        }
                    }
                    current_copy[i] = original;
                }
            }
            if (long_enough)
                return true;
            head = move(next_head);
            for (auto &word : head) {
                wordList.erase(word);
            }
        }
        return false;
    }

    void get_path(
            const string &beginWord,
            const string &endWord,
            const unordered_map<string, vector<string>> &next,
            vector<string> &path,
            vector<vector<string>> &result) {
        if (beginWord == endWord) {
            result.push_back(path);
        } else {
            auto it = next.find(beginWord);
            if (it == next.end()) {
                return;
            }
            for (auto &word : it->second) {
                path.push_back(word);
                get_path(word, endWord, next, path, result);
                path.pop_back();
            }
        }
    }
};


int main()
{
    Solution s;
    unordered_set<string> dict {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    auto rs = s.findLadders("cet", "ism", dict);
    for (auto &r : rs) {
        for (auto &s : r) {
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}
