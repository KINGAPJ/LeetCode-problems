class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector numsCost(n, vector<int>(2));
        for(int i = 0; i < n; i++)
            numsCost[i] = {nums[i], cost[i]};
        sort(numsCost.begin(), numsCost.end());
        
        //prefix sum of costs
        vector<long long> pref(n);
        pref[0] = numsCost[0][1];
        for(int i = 1; i < n; i++)
            pref[i] = pref[i-1] + numsCost[i][1];
        
        long long ans = 0, curr = 0;
        for(int i = 1; i < n; i++)
            curr += 1LL * numsCost[i][1] * (numsCost[i][0] - numsCost[0][0]);
        ans = curr;
        for(int i = 1; i < n; i++){
            long long gap = numsCost[i][0] - numsCost[i-1][0];
            curr += 1LL * pref[i-1] * gap;
            curr -= 1LL * (pref[n-1] - pref[i-1]) * gap;
            ans = min(ans, curr);
        }
        return ans;
    }
};