class Solution {
    vector<vector<int>> dp;
    string s;
    int f(int l, int r){
        if(dp[l][r] != -1)
            return dp[l][r];
        int ans = s.size();
        int j = -1;
        for(int i = l; i < r; i++){
            if(j == -1 && s[i] != s[r]) //takes care of base case
                j = i;
            if(j != -1)
                ans = min(ans, 1 + f(j, i) + f(i+1, r));
        }
        if(j == -1)
            ans = 0;
        return dp[l][r] = ans;
    }
public:
    int strangePrinter(string s) {
        int n = s.size();
        dp = vector(n, vector<int>(n, -1));
        this->s = s;
        return 1+f(0, n-1);
    }
};