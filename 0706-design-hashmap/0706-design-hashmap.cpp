class MyHashMap {
    int table[1000001];
public:
    MyHashMap() {
        memset(table, -1, sizeof(table));
    }
    
    void put(int key, int value) {
        table[key] = value;
    }
    
    int get(int key) {
        return table[key];
    }
    
    void remove(int key) {
        table[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */