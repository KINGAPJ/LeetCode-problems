class Solution {
public:
    /*
        DP:
        dp[i][j] is the maximum number of stones..
            Alice can get when starting at index i with M = j
            
        We maintain a suffix sum to get the sum from index i to last
        The dp matrix for Bob is the same. 
        The strategy for Alice is to choose an optimal X..
            to minimize the number of stones Bob can get when.. 
                starting at index (i + X) with M = max(X,j). 
            
        Recurrence formula:
        dp[i][j] = max(sufsum[i] - dp[i + X][max(j, X)]) where 1<= X <= 2j;
        
    */
    int stoneGameII(vector<int>& piles) {
        int length = piles.size();
        vector<vector<int>>dp(length + 1, vector<int>(length + 1,0));
        vector<int> sufsum (length + 1, 0);
        for (int i = length - 1; i >= 0; i--)
            sufsum[i] = sufsum[i + 1] + piles[i];
        for (int i = 0; i <= length; i++)
            dp[i][length] = sufsum[i];
        for (int i = length - 1; i >= 0; i--) 
            for (int j = length - 1; j >= 1; j--) 
                for (int X = 1; X <= 2 * j && i + X <= length; X++) 
                    dp[i][j] = max(dp[i][j], sufsum[i] - dp[i + X][max(j, X)]);
        return dp[0][1];
    }
};