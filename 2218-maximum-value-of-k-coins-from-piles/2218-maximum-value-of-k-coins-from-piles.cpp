class Solution {
    vector<vector<long>> memo;
    vector<vector<int>> piles;
public:
    long dp(int i, int k){
        // cout<<"i:"<<i<<" k:"<<k<<'\n';
        if(k == 0)
            return 0;
        if(i == 0)
            return piles[i].size() <= k ? piles[i].back() : piles[i][k];
        if(memo[i][k] != -1)
            return memo[i][k];
        long curr = 0;
        for(int j = 0; j <= min(k, (int)piles[i].size()-1); j++){
            // if(j < piles[i].size()){
                curr = max(curr, dp(i-1, k-j) + piles[i][j]);
            // }else{
            //     curr = max(curr, dp(i-1, k));
            // }
        }
        return memo[i][k] = curr;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memo = vector<vector<long>> (n+1, vector<long>(k+1, -1));
        for(int i = 0; i < n; i++){
            for(int j = 1; j < piles[i].size(); j++)
                piles[i][j] += piles[i][j-1];
            piles[i].insert(piles[i].begin(), 0);
        }
        this->piles = piles;
        // cout<<'\n';
        return dp(n-1, k);
    }
};