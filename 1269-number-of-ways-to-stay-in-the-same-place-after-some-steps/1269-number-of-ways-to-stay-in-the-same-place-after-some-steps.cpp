class Solution {
    const int mod = 1e9 + 7;
public:
    //Knight Dialer
    int numWays(int steps, int arrLen) {
        int n = min(steps/2 + 1, arrLen);
        vector<int> v1(n+2), v2(n+2);
        v1[1] = 1;
        while(steps--){
            for(int i = 1; i <= n; i++)
                v2[i] = ((long)v1[i] + v1[i-1] + v1[i+1]) % mod;
            swap(v1, v2);
        }
        return v1[1];
    }
};