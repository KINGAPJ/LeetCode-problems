class Solution {
public:
    /*
        Table:
        parameters: left, right
        recurrence relation: 
        dp[l][r] = if(s[l] == s[r]) 2 + dp[l+1][r-1]
                            else    max(dp[l][r-1], dp[l+1][r])
        order: we have to do all lengths for all indices starting from length 1 so that we can cover bigger ranges and of course order is reverse of memoization
    */
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int l = n-1; l >= 0; l--)
            for(int r = l; r < n; r++){
                if(l == r){
                    dp[l][r] = 1;
                    continue;
                }
                dp[l][r] = (s[l] == s[r]) ? 2 + dp[l+1][r-1] : 
                                            max(dp[l][r-1], dp[l+1][r]);
            }
        return dp[0][n-1];
    }
};