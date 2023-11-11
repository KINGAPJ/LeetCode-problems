class Solution {
    vector<vector<int>> dp;
    int f(vector<int> &houses, int i, int k){
        int n = houses.size();
        if(i >= n)
            return 0;
        if(k >= (n-i))
            return 0;
        if(k == 1){
            int ret = 0, midPt = houses[i+(n-i)/2]; //median
            for(int j = i; j < n; j++)
                ret += abs(midPt - houses[j]);
            return ret;
        }
        if(dp[i][k] != -1)
            return dp[i][k];
        int ans = INT_MAX, median = i-1, currdist = 0;
        for(int j = i; j < n; j++){
            if(!((j-i)&1))
                median++;
            currdist += abs(houses[j] - houses[median]);
            ans = min(ans, currdist + f(houses, j+1, k-1));
        }
        return dp[i][k] = ans;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        dp = vector(n, vector<int>(k+1, -1));
        int ans = f(houses, 0, k);
        return ans;
    }
};