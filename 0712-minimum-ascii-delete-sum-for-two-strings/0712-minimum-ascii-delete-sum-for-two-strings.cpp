class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for(int j = 1; j <= n; j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
                }
                // else{
                //     dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
                // }
            }
        }
        // for(int i = 0; i <= m; i++){
        //     for(int j = 0; j <= n; j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        return dp[m][n];
    }
};