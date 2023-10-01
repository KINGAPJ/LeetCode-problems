#define ll long long
class Solution {
    const ll mod = 1e9 + 7;
    ll _p(ll x, ll n){
        x %= mod;
        ll res = 1;
        while(n){
            if(n&1)
                res = (res * x) % mod;
            n >>= 1;
            x = (x * x) % mod;
        }
        return res;
    }
public:
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors <= 4)
            return primeFactors;
        int rem = primeFactors % 3;
        int pow3 = primeFactors/3;
        int pow2 = 0;
        if(rem == 1)
            pow3--, pow2 += 2;
        else if(rem == 2)
            pow2++;
        return (_p(3LL, pow3) * (1LL<<pow2)) % mod;
    }
};