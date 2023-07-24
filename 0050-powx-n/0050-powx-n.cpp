class Solution {
public:
    double myPow(double x, int n) {
        if(x < 0 && n&1){
            return -myPow(abs(x), n);
        }
        if(n < 0){
            if(n == INT_MIN)
                return 1/(x*myPow(x, INT_MAX));
            return 1/myPow(x, abs(n));
        }
        double ans = 1;
        while(n){
            if(n&1)
                ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};