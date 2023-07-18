class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> pos; //key -> iterator in list
    list<pair<int, int>> cache;
    int size = 0;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(pos.count(key)){
            int value = pos[key]->second;
            cache.erase(pos[key]);
            cache.push_front({key, value});
            pos[key] = cache.begin();
            return value;
        }else
            return -1;
    }
    
    void put(int key, int value) {
        if(pos.count(key))
            cache.erase(pos[key]);
        cache.push_front({key, value});
        pos[key] = cache.begin();
        if(cache.size() > size){
            pos.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */