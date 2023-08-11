class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto &j: coins)
            for(int i = 1; i <= amount; i++){
                dp[i] += (i >= j) ? dp[i-j] : 0;
        }
        return dp[amount];
    }
};