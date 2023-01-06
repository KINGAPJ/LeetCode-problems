class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0, i = 0;
        while(i < costs.size() && coins - costs[i] >= 0)
            coins -= costs[i++], ans++;
        return ans;
    }
};