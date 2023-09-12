class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1] = 1, dp[0] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= i; j++){
                dp[i] = max(dp[i], dp[i-j]*j);
            }
        }
        return n <= 3 ? dp[n-1] : dp[n];
    }
};