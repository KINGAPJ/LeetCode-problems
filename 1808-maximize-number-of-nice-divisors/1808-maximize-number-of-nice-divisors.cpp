class Solution {
    const long long mod = 1e9 + 7;
    long long _p(long long x, long long n){
        x %= mod;
        long long res = 1;
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