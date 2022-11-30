class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ;
        unordered_set<int> s;
        for(int &i: arr)
            occ[i]++;
        for(auto &i: occ){
            if(s.count(i.second))
                return false;
            else s.insert(i.second);
        }
        return true;
    }
};