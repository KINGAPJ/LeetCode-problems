class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(2, vector<int>(n));
        int remov = 0;
        for(int j = 0; j < m; j++){
            dp[0] = dp[1];
            for(int i = 0; i < n; i++){
                if(text1[i] == text2[j])
                    dp[1][i] = (i > 0) ? dp[0][i-1] + 1 : 1;
                else dp[1][i] = (i > 0) ? max(dp[0][i], dp[1][i-1]) : dp[0][i];
            }
        }
        return dp[1][n-1];
    }
};