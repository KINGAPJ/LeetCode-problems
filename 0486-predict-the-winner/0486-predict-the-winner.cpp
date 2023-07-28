class Solution {
private:
    vector<vector<vector<int>>> dp;

    int recur(vector<int> &nums, int start, int end, int player)
    {
        int ans=player?-1:1;
        if(start>end)
            return 0;
        cout<<start<<" "<<end<<" "<<player<<" "<<dp[start][end][player]<<endl;
        if(dp[start][end][player]!=INT_MIN)
            return dp[start][end][player];
        int a = ans*nums[start]+recur(nums,start+1,end,1-player);
        int b = ans*nums[end]+recur(nums,start,end-1,1-player);
        if(player)
            ans= min(a,b);
        else
            ans= max(a,b);
        return dp[start][end][player]=ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums)
    {
        // memset(dp,-100,sizeof(dp));
        dp.resize(22, vector<vector<int>>(22, vector<int>(2, INT_MIN)));
        return recur(nums,0,nums.size()-1,0)>=0;
    }
};