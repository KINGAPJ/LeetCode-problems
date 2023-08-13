class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(3);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            int ind = i+1;
            bool ans = false;
            if(i-1 >= 0 && nums[i-1] == nums[i])
                ans |= dp[(ind-2)%3];
            if(i-2 >= 0 && nums[i-2] == nums[i-1] && nums[i-1] == nums[i])
                ans |= dp[(ind-3)%3];
            if(i-2 >= 0 && nums[i-2]+1 == nums[i-1] && nums[i-1]+1 == nums[i])
                ans |= dp[(ind-3)%3];
            dp[ind%3] = ans;
        }
        return dp[n%3];
    }
};