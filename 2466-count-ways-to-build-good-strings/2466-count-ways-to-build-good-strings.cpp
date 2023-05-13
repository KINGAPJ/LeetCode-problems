class Solution {
    vector<long> dp;
    long z, o;
    const long mod = 1e9 + 7;
public:
    long f(long leng){
        if(leng == 0)
            return 1;
        if(leng < 0)
            return 0;
        if(dp[leng] != -1)
            return dp[leng];
        return dp[leng] = ((f(leng - z))%mod + (f(leng - o))%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        z = zero;
        o = one;
        dp = vector<long>(high+1, -1);
        long ans = 0;
        for(long i = high; i >= 0; i--)
            f(i);
        // for(long i = 0; i <= 3; i++)
        //     cout<<i<<':'<<dp[i]<<'\n';
        for(int i = 0; i < high; i++)
            if(dp[i] == -1)
                dp[i] = 0;
        for(long i = low; i <= high; i++)
            ans = (ans + dp[i]) % mod;
        return ans;
    }
};