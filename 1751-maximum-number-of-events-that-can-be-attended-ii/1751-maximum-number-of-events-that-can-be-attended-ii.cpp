class Solution {
    vector<vector<int>> events;
    vector<vector<int>> dp;
    vector<int> ends;
public:
    int f(int i, int k){
        int n = events.size();
        // cout<<i<<' '<<k<<' ';
        // cout<<'\n';
        // for(int j = 0; j < n; j++)
        //     cout<<events[j][0]<<' ';
        // cout<<'\n';
        if(i == 0 || k == 0)
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int j = lower_bound(ends.begin(), ends.end(), events[i-1][0]) - ends.begin();
        //j is index of first element in ends, but since 1 indexing, it corresponds to largest element
        //smaller than this
        // cout<<j<<'\n';
        return dp[i][k] = max(f(i-1, k), events[i-1][2] + f(j, k-1));
    }
    int maxValue(vector<vector<int>>& evnts, int k) {
        events = evnts;
        int n = events.size();
        sort(events.begin(), events.end(), [&](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        for(int i = 0; i < n; i++)
            ends.push_back(events[i][1]);
        dp = vector<vector<int>>(n+1, vector<int>(k+1, -1)); //1-indexed dp
        int ans = f(n, k);
        return ans;
    }
};