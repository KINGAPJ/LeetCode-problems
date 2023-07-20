class Solution {
    vector<vector<int>> dp;
    string s;
    bool check(string &a, string &b){
        int n = a.size();
        if(a.size() != b.size())
            return false;
        for(int i = 0; i < n; i++){
            if(a[i] != b[n-1-i])
                return false;
        }
        return true;
    }
    int f(int l, int r){
        int n = s.size();
        // cout<<l<<' '<<r<<'\n';
        if(l > r || r >= n || l < 0)
            return 0;
        if(l == r)
            return 1;
        if(dp[l][r] != -1)
            return dp[l][r];
        if(s[l] == s[r])
            return dp[l][r] = 2 + f(l+1, r-1);
        string a = "", b = "";
        a.push_back(s[l]);
        b.push_back(s[r]);
        l++, r--;
        while(!check(a, b) && l < r){
            // cout<<a<<' '<<b<<'\n';
            a.push_back(s[l++]);
            b.push_back(s[r--]);
        }
        // cout<<a<<' '<<b<<'\n';
        if(check(a, b))
            return dp[l][r] = 2 + f(l, r);
        else
            return dp[l][r] = 1;
        // return dp[l][r] = 2 + f(l, r);
    }
public:
    int longestDecomposition(string text) {
        int n = text.size();
        s = text;
        dp = vector (n, vector<int>(n, -1));
        return f(0, n-1);
        // for(int l = 0; l < n; l++)
        //     for(int r = l; r < n; r++)
        //         dp[l][r] = 1;
        // for(int l = n-2; l >= 0; l--){
        //     for(int r = l+1; r < n; r++){
        //         if(text[l] == text[r])
        //             dp[l][r] = max(dp[l][r], 2 + dp[l+1][r-1]);
        //         else{
        //             dp[l][r] = max(dp[l][r], min(dp[l+1][r], dp[l][r-1]));
        //             // if(text[l] == text[r-1])
        //             //     dp[l][r] = max(dp[l][r], dp[l+1][r]);
        //         }
        //     }
        // }
        // for(int i = 0; i < n; i++)
        //     cout<<text[i]<<' ';
        // cout<<'\n';
        // for(int l = 0; l < n; l++){
        //     for(int r = 0; r < n; r++)
        //         cout<<dp[l][r]<<' ';
        //     cout<<'\n';
        // }
        // return dp[0][n-1];
    }
};