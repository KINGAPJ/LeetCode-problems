struct Node{
    int key, val, frq;
    Node *next, *prev;
    Node() {key = 0, val = 0, frq = 1, next = nullptr, prev = nullptr; }
    Node(int k, int v)
    { key = k, val = v, frq = 1, next = nullptr, prev = nullptr; }
};

struct List{
    Node *head, *tail;
    //head is a dummy node pointing to the next node which is first node and so is tail
    int sz;
    List(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        sz = 0;
    }
    Node* back()  { return tail->prev; }
    void remove(Node* node){
        if(node->prev)
            node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
        delete node;
        sz--;
    }
    void pushFront(Node* node){
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
        sz++;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyNode; //existence
    unordered_map<int, List*> freqList; //frequency list
    int cap, minFrq, cacheSize;
    
    void makeRU(int key, int val, int frq){ //RU: Recently Used
        if(!freqList[frq])
            freqList[frq] = new List(); //essential to create dummy head and tail
        Node* newnode = new Node(key, val);
        newnode->frq = frq;
        freqList[frq]->pushFront(newnode);
        keyNode[key] = newnode;
    }
    
    void updateFreq(Node* node){
        int frq = node->frq, val = node->val, key = node->key;
        
        //deleting from orig pos
        freqList[frq]->remove(node);
        if(frq == minFrq && freqList[frq]->sz == 0)
            minFrq++;
        keyNode.erase(key);
        
        //putting curr key into higher frq
        frq++;
        makeRU(key, val, frq);
    }
    
public:    
    LFUCache(int capacity) {
        cap = capacity;
        cacheSize = 0;
        minFrq = 0;
    }
    
    int get(int key) {
        if(!keyNode.count(key))
            return -1;
        Node* node = keyNode[key];
        int value = node->val;
        updateFreq(node);
        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        if(keyNode.count(key)){
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        }else{
            if(cacheSize == cap){
                Node* node = freqList[minFrq]->back();
                keyNode.erase(node->key);
                freqList[minFrq]->remove(node);
                cacheSize--;
            }
            makeRU(key, value, 1);
            cacheSize++;
            minFrq = 1;
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */