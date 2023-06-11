class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 3, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 4;
        for(int i = 3; i <= target; i++){
            int k = 1+log2(i);
            if(i == (1<<k)-1){
                dp[i] = k;
                continue;
            }
            for(int j = 0; j < k-1; j++) 
                dp[i] = min(dp[i], dp[i-(1<<(k-1))+(1<<j)] + k-1 + j + 2);
                //A^(k-1).R.A^j.R
            if((1<<k) - 1 - i < i) // to not redo the part in the continue block-1
                dp[i] = min(dp[i], dp[(1<<k) - 1 - i] + k + 1);
                //A^k.R
        }
        return dp[target];
    }
};