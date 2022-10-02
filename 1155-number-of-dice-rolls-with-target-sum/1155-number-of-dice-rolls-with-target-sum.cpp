class Solution {
public:
    const int mod = 1e9+7;
    int dp(vector<vector<int>>& memo, int n, int k, int t){
        if(t == 0){
            if(n == 0)
                return 1;
            else return 0;
        }else if(t < 0)
            return 0;
        else if(n < 0)
            return 0;
        if(memo[n][t] != -1)
            return memo[n][t];
        int curr = 0;
        for(int i = 1; i <= k; i++)
            curr = (curr + dp(memo, n-1, k, t-i)) % mod;
        return memo[n][t] = curr;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n+1, vector<int>(target+1, -1));
        return dp(memo, n, k, target);
    }
};