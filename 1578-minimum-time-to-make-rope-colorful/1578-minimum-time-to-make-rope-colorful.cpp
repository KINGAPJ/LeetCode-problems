class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0, max_cost = 0, sum_cost = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] != s[i - 1]) {
                ans += sum_cost - max_cost;
                sum_cost = 0;
                max_cost = 0;
            }
            sum_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        ans += (sum_cost - max_cost);
        return ans;
    }
};