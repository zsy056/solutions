#include <unordered_map>
#include <list>

using namespace std;

struct Item {
    int val;
    list<int>::iterator it;
    Item(int val, list<int>::iterator &it): val(val), it(it) {}
};


class LRUCache{
public:
    LRUCache(int capacity): capacity(capacity) {

    }

    int get(int key) {
        auto cache_it = cache.find(key);
        if (cache_it == cache.end()) {
            return -1;
        }
        auto it = cache_it->second.it;
        lru.erase(it);
        lru.push_front(key);
        cache_it->second.it = lru.begin();
        return cache_it->second.val;
    }

    void set(int key, int value) {
        auto cache_it = cache.find(key);
        if (cache.size() == capacity && cache_it == cache.end()) {
            auto it = --lru.end();
            cache.erase(*it);
            lru.erase(it);
        }
        lru.push_front(key);
        auto it = lru.begin();
        if (cache_it != cache.end()) {
            lru.erase(cache_it->second.it);
            cache_it->second = Item(value, it);
        } else {
            cache.insert({key, Item(value, it)});
        }
    }

private:
    int capacity;
    unordered_map<int, Item> cache;
    list<int> lru;
};
