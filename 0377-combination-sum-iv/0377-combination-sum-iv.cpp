class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target + 1);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for(unsigned i = 0; i <= target; i++){
            for(auto &j: nums){
                if(j > i)
                    break;
                else
                    dp[i] += dp[i-j];
            }
        }
        return dp[target];
    }
};