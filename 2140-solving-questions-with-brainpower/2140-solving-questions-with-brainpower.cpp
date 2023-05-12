class Solution {
public:
    //recursive opposite direction of iterative
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(2e5 + 1);
        for (int i = n - 1; i >= 0; i--)
            dp[i] = max(questions[i][0] + dp[questions[i][1] + i + 1], dp[i + 1]);
        return dp[0];
    }
};