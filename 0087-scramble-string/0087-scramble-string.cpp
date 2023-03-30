class Solution {
public:
    /*
    //////////////////scrap it
        abcde dceba caebd
        12345 43521 31524
        
        1->4 xor 1235
        2->43 xor 125
        3->435 xor 12
        4->4352
        5->43521
        after one rounf, we give 3, and 3-5:345 1-3:435 to one child, 12 and 12 to other
        
    */
    
    //we can use bottom-up DP, which is O(N^4) complexity. Here we build a table isS[len][i][j], which indicates whether s1[i..i+len-1] is a scramble of s2[j..j+len-1].
    bool isScramble(string s1, string s2) {
        int n = s1.size(), len, i, j, k;
        if(n == 0) 
            return true;
        if(n == 1) 
            return s1 == s2;
        bool dp[n+1][n][n];

        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                dp[1][i][j] = (s1[i] == s2[j]);
                
        for(len = 2; len <= n; len++)
            for(i = 0; i <= n-len; i++)
                for(j = 0; j <= n-len; j++){
                    dp[len][i][j] = false;
                        for(k = 1; k < len && !dp[len][i][j]; ++k){
                            dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len-k][i+k][j+k]);
                            dp[len][i][j] = dp[len][i][j] || (dp[k][i+len-k][j] && dp[len-k][i][j+k]);
                        }
                }
        
        return dp[n][0][0];            
    }
};