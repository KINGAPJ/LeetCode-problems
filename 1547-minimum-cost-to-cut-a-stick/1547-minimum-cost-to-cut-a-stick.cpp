class Solution {
    vector<int> cut;
    vector<vector<int>> dp;
public:
    int f(int l, int r){
        if(r <= l+1)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        int ans = INT_MAX;
        for(int i = l+1; i < r; i++)
            ans = min(ans, cut[r] - cut[l] + f(l, i) + f(i, r));
        return dp[l][r] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        cut = cuts;
        dp = vector<vector<int>>(105, vector<int>(105, -1));
        return f(0, cuts.size()-1);
    }
};