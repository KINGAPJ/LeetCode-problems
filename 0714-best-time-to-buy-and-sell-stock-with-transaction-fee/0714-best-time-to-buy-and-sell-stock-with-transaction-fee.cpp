class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0, curr = prices[0], n = prices.size();
        for(int i = 1; i < n; i++){
            if(prices[i] < curr){
                curr = prices[i];
            }else if(prices[i] > curr + fee){
                ans += prices[i] - fee - curr;
                curr = prices[i] - fee;
            }
        }
        return ans;
    }
};