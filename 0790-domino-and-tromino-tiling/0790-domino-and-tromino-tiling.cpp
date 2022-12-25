#define ll long long
const ll mod = 1e9 + 7;
class Solution {
    vector<vector<ll>> memo;
public:
    ll dp(ll n, bool odd){
        if(n == 0)
            return 0;
        if(n <= 2)
            return n;
        if(memo[n][odd] != -1)
            return memo[n][odd];
        ll curr = 0;
        if(odd == true){ // there is an extra dot
            curr = (curr + dp(n-1, false)) % mod; //put a three dotter and remove the extra
            curr = (curr + dp(n-1, true)) % mod; //put a two dotter and keep the extra on opposite side
        }else{
            curr = (curr + 2*dp(n-2, true)) % mod; //three dotters in 2 ways
            curr = (curr + dp(n-1, false)) % mod; //vertical two dotter
            curr = (curr + dp(n-2, false)) % mod; //2 horizontal two dotters
        }
        return memo[n][odd] = curr;
    }
    int numTilings(int n) {
        memo = vector<vector<ll>>(n+1, (vector<ll>(2, -1)));
        return dp(n, false) % mod;
    }
};