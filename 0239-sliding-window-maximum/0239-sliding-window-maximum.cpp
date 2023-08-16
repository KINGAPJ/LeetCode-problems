class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(i-k >= 0){
                if(--mp[nums[i-k]] == 0)
                    mp.erase(nums[i-k]);
            }
            if(i >= k-1)
                ans.push_back((mp.rbegin())->first);
        }
        return ans;
    }
};