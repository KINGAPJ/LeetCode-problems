class Solution {
public:
    const long long mod = 1e9+7;
    int concatenatedBinary(int n) {
        long long i = 2, j = 1, ans = 1;
        while(i <= n){
            if(i < pow(2, j)){
                ans = ((ans<<j) + i++) % mod;
            }else{
                ans = ((ans<<(++j)) + i++) % mod;
            }
        }
        return ans;
    }
};