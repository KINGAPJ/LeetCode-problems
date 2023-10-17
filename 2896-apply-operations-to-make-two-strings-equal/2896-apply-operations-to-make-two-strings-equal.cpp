class Solution {
    vector<vector<int>> dp;
    int func(int idx, vector<int> &v, int x, int flag) {
        int n = v.size();
        if(idx == n) {
            return 0;
        }

        if(dp[idx][flag] != -1) return dp[idx][flag];

        int ans = INT_MAX;
        if(idx < n-1) {
            ans = min(ans, v[idx+1] - v[idx] + func(idx+2, v, x, flag));
        }
        if(flag)
            ans = min(ans, func(idx+1, v, x, false));
        else
            ans = min(ans, x + func(idx+1, v, x, true));

        return dp[idx][flag] = ans;
    }
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> v;
        int n = s1.size();
        dp = vector<vector<int>> (n+1, vector<int> (2, -1));
        
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i])
                v.push_back(i);
        }

        if(v.size() % 2)
            return -1;
        return func(0, v, x, 0);
    }
};