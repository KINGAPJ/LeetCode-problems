class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(auto &x: nums)
            hash[x]++;
        set<pair<int, int>> ans;
        for(auto &x: hash){
            if(ans.size() < k)
                ans.insert({x.second, x.first});
            else if(ans.size() == k){
                ans.insert({x.second, x.first});
                ans.erase(ans.begin());
            }
        }
        vector<int> res;
        for(auto x: ans)
            res.push_back(x.second);
        return res;
    }
};