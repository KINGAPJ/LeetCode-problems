class Solution {
public:
    const int mod = 1e9+7;
    #define ll long long
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        ll ans = 0;
        sort(arr.begin(), arr.end());
        map<ll, ll> dp;
        for(auto &i: arr){
            int curr = 1;
            for(auto &j: dp){
                if(i % j.first == 0 && dp.count(i/j.first)){
                    curr %= mod;
                    curr += ((j.second % mod) * (dp[i/j.first] % mod)) % mod;
                }
            }
            dp[i] = curr % mod;
            ans %= mod;
            ans += curr % mod;
        }
        return ans % mod;
    }
};