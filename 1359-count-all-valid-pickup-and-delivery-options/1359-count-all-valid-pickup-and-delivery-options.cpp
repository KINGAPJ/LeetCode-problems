#define ll long long
class Solution {
    const ll mod = 1e9 + 7;
public:
    int countOrders(int n) {
        if(n == 1)
            return 1;
        ll ans = 1;
        for(int i = 2; i <= n; i++){
            ll spaces = 2*(i-1)+1;
            ll multiplier = spaces*(spaces+1)/2;
            ans = (ans * multiplier) % mod;
        }
        return ans;
    }
};