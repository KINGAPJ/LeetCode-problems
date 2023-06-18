class Solution {
    vector<vector<int>> dp;
    vector<int> cost, time;
public:
    int f(int i, int rem){
        int n = cost.size();
        if(rem <= 0)
            return 0;
        if(i == n){
            return 1e9;
        }
        if(dp[i][rem] != -1)
            return dp[i][rem];
        int ans = f(i+1, rem);
        ans = min(ans, cost[i]+f(i+1, rem-1-time[i]));
        return dp[i][rem] = ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        this->cost = cost;
        this->time = time;
        dp = vector (n+1, vector<int>(n+1, -1));
        return f(0, n);
    }
};