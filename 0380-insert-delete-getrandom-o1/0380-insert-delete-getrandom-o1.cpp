class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> ind; //num->ind
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(ind.count(val))
            return false;
        nums.push_back(val);
        ind[val] = (int)nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!ind.count(val))
            return false;
        int rem_ind = ind[val], n = nums.size();
        swap(nums[rem_ind], nums[n-1]);
        ind[nums[rem_ind]] = rem_ind;
        ind.erase(nums[n-1]);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        return nums[rand()%n]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */