class Solution {
    int dp[100001][2];
    int maxSum = INT_MIN;
    int f(vector<int>& arr, int i, bool removed){
        int n = arr.size();
        if(i == n)
            return -1e9;
        if(dp[i][removed] != -1)
            return dp[i][removed];
        int ans = max(arr[i], arr[i] + f(arr, i+1, removed));
        if(!removed)
            ans = max(ans, f(arr, i+1, true));
        maxSum = max(maxSum, ans);
        return dp[i][removed] = ans;
    }
public:
    int maximumSum(vector<int>& arr) {
        memset(dp, -1, sizeof dp);
        f(arr, 0, false);
        return maxSum;
    }
};