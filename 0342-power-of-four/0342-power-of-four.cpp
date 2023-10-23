class Solution {
public:
    bool isPowerOfFour(int n) {
        double k = log(n)/log(4);
        return k - floor(k) == 0;
    }
};