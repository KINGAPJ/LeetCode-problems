class Solution {
public:
    // O(n) time and O(1) space
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4);
        for (int i = n - 1; i >= 0; i--) {
            dp[i % 4] = -1e9;
            for (int k = 0, take = 0; k < 3 && i + k < n; k++)
                dp[i % 4] = max(dp[i % 4], (take += stoneValue[i + k]) - dp[(i + k + 1) % 4]);
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};