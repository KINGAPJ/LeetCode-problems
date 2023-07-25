#define ll long long
class Solution {
    int n;
    const int mod = 1e9 + 7;
    vector<vector<vector<ll>>> dp;
    ll f(int i, int k, bool line){
        if(i == n){
            if(k == 0 && !line){
                return 1;
            }else{
                return 0;
            }
        }
        if(k < 0)
            return 0;
        if(dp[i][k][line] != -1)
            return dp[i][k][line];
        ll ans = 0;
        if(!line){//if the line is not ongoing            
            //start new line
            ans = (ans + f(i+1, k, true)) % mod;
            //continue emptiness
            ans = (ans + f(i+1, k, false)) % mod;
        }else{
            //continue line
            ans = (ans + f(i+1, k, true)) % mod;
            //start new line by ending this
            ans = (ans + f(i+1, k-1, true)) % mod;
            //end this but start emptiness
            ans = (ans + f(i+1, k-1, false)) % mod;
        }
        return dp[i][k][line] = ans;
    }
public:
    int numberOfSets(int n, int k) {
        this->n = n;
        dp = vector(n+1, vector(k+1, vector<ll>(2, -1)));
        return f(0, k, false);
    }
};