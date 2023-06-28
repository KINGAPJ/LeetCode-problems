class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n, 0);
        for(int i = 0; i < forget; i++)
            dp[i] = 1;
        for(int i = 0; i < n; i++){
            for(int x = delay; x < forget && i+x < n; x++)
                dp[i+x] = (dp[i+x] + dp[i]) % 1000000007;
        }
        return dp[n-1];
    }
};