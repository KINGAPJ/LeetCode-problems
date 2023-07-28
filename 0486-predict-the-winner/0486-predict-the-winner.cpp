class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int l = n-1; l >= 0; l--){
            for(int r = l; r < n; r++){
                if(l == r)
                    dp[l][r] = nums[l];
                else
                    dp[l][r] = max(nums[l] - dp[l+1][r], nums[r] - dp[l][r-1]);
            }
        }
        int player1 = (dp[0][n-1] + sum)/2;
        if(player1 < (sum - player1))
            return false;
        return true;
    }
};