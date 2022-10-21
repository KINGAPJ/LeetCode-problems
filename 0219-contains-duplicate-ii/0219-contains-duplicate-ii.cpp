class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i])){
                if(mp[nums[i]].back() >= i - k)
                    return true;
            }
            mp[nums[i]].push_back(i);
        }
        return false;
    }
};