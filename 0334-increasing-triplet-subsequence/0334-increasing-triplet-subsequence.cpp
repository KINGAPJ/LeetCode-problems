class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(auto &i: nums){
            auto ind = lower_bound(dp.begin(), dp.end(), i);
            if(ind == dp.end())
                dp.push_back(i);
            else dp[ind-dp.begin()] = i;
            if(dp.size() == 3)
                return true;
        }
        return false;
    }
};