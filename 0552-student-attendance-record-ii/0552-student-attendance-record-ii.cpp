class Solution {
    long long dp[100001][2][2][2];
    const long long mod = 1e9 + 7;
    //0: present, 1: late, 0,abs-1: absent
    long long f(int i, int prev, int pprev, int ab){
        if(ab == -1)
            return 0;
        if(i == 0)
            return 1;
        if(dp[i][prev][pprev][ab] != -1)
            return dp[i][prev][pprev][ab];
        long long ans = 0;
        if(prev == 1 && pprev == 1){
            ans = (ans + f(i-1, 0, prev, ab)) % mod;
            ans = (ans + f(i-1, 0, prev, ab-1)) % mod;
        }else{
            ans = (ans + f(i-1, 0, prev, ab)) % mod;
            ans = (ans + f(i-1, 1, prev, ab)) % mod;
            ans = (ans + f(i-1, 0, prev, ab-1)) % mod;
        }
        return dp[i][prev][pprev][ab] = ans;
    }
public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n, 0, 0, 1);
    }
};