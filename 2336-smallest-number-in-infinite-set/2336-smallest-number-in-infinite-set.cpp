class SmallestInfiniteSet {
    unordered_set<int> popped;
    priority_queue<int, vector<int>, greater<int>> added;
public:
    SmallestInfiniteSet() {}
    int popSmallest() {
        int remove = -1;
        if(added.empty()){
            remove = popped.size() + 1;
        }else{
            remove = added.top();
            added.pop();
        }
        popped.insert(remove);
        return remove;
    }
    void addBack(int num) {
        if(popped.count(num)){
            popped.erase(num);
            added.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */