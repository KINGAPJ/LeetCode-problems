class Solution {
    vector<int> stones;
    vector<vector<int>> dp;
    int f(int i, int p){
        int n = stones.size();
        // cout<<p<<" "<<i<<endl;
        if(i == n-1) 
            return 1;
        if(dp[i][p] != -1) 
            return dp[i][p];
        int prevjump = stones[i] - stones[p];
        int res = 0;
        for(int j = prevjump-1; j <= prevjump+1; j++) {
            int nextStone = stones[i] + j;
            int ind = lower_bound(stones.begin(), stones.end(), nextStone) - stones.begin();
            if(ind != n && ind != i && stones[ind] == nextStone){
                res = (res || (f(ind, i)));
            }
        }
        return dp[i][p] = res;
    }
public:    
    bool canCross(vector<int>& stones) {
        this->stones = stones;
        int n = stones.size();
        dp = vector (n, vector<int>(n, -1));
        return f(0, 0);
    }
};