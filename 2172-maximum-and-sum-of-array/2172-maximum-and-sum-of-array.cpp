class Solution {
    int dp[300000];
    int ns;
    int f(int i, vector<int>& nums, int mask){
        int n = nums.size();
        if(i == n)
            return 0;
        if(dp[mask] != -1)
            return dp[mask];
        int ans = 0;
        for(int j = 0; j < 2*ns; j++){
            int idx = j/2+1;
            if(!(mask & (1<<j)))
                ans = max(ans, (nums[i]&idx) + f(i+1, nums, mask | (1<<j)));
        }
        return dp[mask] = ans;
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        ns = numSlots;
        memset(dp, -1, sizeof(dp));
        int ans = f(0, nums, 0);
        return ans;
    }
};