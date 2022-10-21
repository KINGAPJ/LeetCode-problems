class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        //dp[i][j] : 
        //minimum number of changes required in first i elements such that the xor value = j 
        int n = nums.size();
        int frq[k][1025];
        memset(frq, 0, sizeof(frq));
        for(int i = 0; i < n; i++)
            frq[i%k][nums[i]]++;
        int dp[k+1][1025];
        memset(dp, 1e9+1, sizeof(dp));
        dp[0][0] = 0;
        int prevMin = 0;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < 1025; j++){
                for(int l = i; l < n; l += k){
                    if((j^nums[l]) < 1025)
                        //ceil((n-i)/k): 
                        dp[i+1][j^nums[l]] = min(dp[i+1][j^nums[l]], 
                                                dp[i][j] + (n-i+k-1)/k - frq[i][nums[l]]);
                }
            }
            int prevMin2 = 1e9+1;
            for(int j = 0; j < 1025; j++){
                dp[i+1][j] = min(dp[i+1][j], (n-i+k-1)/k + prevMin);
                prevMin2 = min(prevMin2, dp[i+1][j]);
            }
            prevMin = prevMin2;
        }
        return dp[k][0];
    }
};