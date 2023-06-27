class Solution {
    vector<int> num;
    vector<string> digs;
    vector<vector<vector<int>>> dp;
    int f(int i, bool tight, bool ldg){
        int n = num.size();
        if(i == n)
            return 1;
        if(dp[i][tight][ldg] != -1)
            return dp[i][tight][ldg];
        int ans = 0;
        bool newtight = false;
        int k = tight ? num[i] : 9;
        // cout<<k<<'\n';
        if(ldg){
            ans += f(i+1, false, ldg);
        }
        for(int j = 0; j < digs.size() && digs[j][0]-'0' <= k; j++){
            // cout<<i<<(tight?" true ":" false ")<<digs[j][0]-'0'<<'\n';
            newtight = digs[j][0]-'0' == num[i] ? tight : false;
            ans += f(i+1, newtight, false);
        }
        return dp[i][tight][ldg] = ans;
    }
    void digits(int n){
        vector<int> dig;
        while(n){
            dig.push_back(n%10);
            n /= 10;
        }
        reverse(dig.begin(), dig.end());
        num = dig;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digts, int n) {
        digits(n);
        sort(digts.begin(), digts.end());
        digs = digts;
        int x = num.size();
        dp = vector(x+1, vector(2, vector<int>(2, -1)));
        return f(0, true, true)-1;
    }
};