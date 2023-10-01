class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int minm = nums[0];
        for(int i = 2; i < n; i++){
            mp[nums[i]]++;
        }
        // cout<<'\n';
        for(int i = 1; i < n-1; i++){
            // for(auto &x: mp){
            //     cout<<x.first<<":"<<x.second<<' ';
            // }
            // cout<<'\n';
            auto x = mp.upper_bound(minm);
            // if(x == mp.end()){
            //     if(--mp[nums[i+1]] == 0)
            //         mp.erase(nums[i+1]);
            //     minm = min(minm, nums[i]);
            //     continue;
            // }
            // cout<<"("<<minm<<","<<
            if(x != mp.end() && minm < nums[i] && (*x).first < nums[i])
                return true;
            if(--mp[nums[i+1]] == 0)
                mp.erase(nums[i+1]);
            minm = min(minm, nums[i]);
        }
        return false;
    }
};