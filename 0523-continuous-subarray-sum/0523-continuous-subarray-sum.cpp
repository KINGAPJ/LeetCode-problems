class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            if(!mp.count(curr%k))
                mp[curr%k] = i+1;
            else if(mp[curr%k] < i)
                return true;
        }
        return false;
    }
};