class Solution {
    vector<int> bits;
    vector<vector<vector<int>>> dp;
    int f(int i, bool tight, int prev){
        int n = bits.size();
        if(i == n)
            return 0;
        if(dp[i][tight][prev] != -1)
            return dp[i][tight][prev];
        int ans = 0;
        bool newtight = false;
        int k = tight ? bits[i] : 1;
        for(int j = 0; j <= k; j++){
            newtight = (j == bits[i]) ? tight : false;
            if(j == 1 && prev == 1){
                if(tight){
                    int rem = 0;
                    for(int x = i+1; x < n; x++)
                        rem = (rem<<1)+bits[x];
                    ans += rem+1;
                }else
                    ans += (1<<(n-1-i));
            }else
                ans += f(i+1, newtight, j);
        }
        return dp[i][tight][prev] = ans;
    }
public:
    int findIntegers(int n) {
        vector<int> bs;
        int N = n;
        while(n){
            bs.push_back(n%2);
            n/=2;
        }
        reverse(bs.begin(), bs.end());
        bits = bs;
        dp = vector(bits.size()+1, vector<vector<int>>(2, vector<int>(2, -1)));
        return N+1 - f(0, true, 0);
    }
};