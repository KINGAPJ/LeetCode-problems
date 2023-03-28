class Solution {
    map<int, int> ds;
    vector<int> memo;
public:
    int dp(vector<int>& days, vector<int>& costs, int i){
        if(i >= days.size())
            return 0;
        if(memo[i] != -1)
            return memo[i];
        int ans = 0;
        auto one = ds.lower_bound(days[i]+1);
        auto two = ds.lower_bound(days[i]+7);
        auto three = ds.lower_bound(days[i]+30);
        int one1 = 0, two2 = 0, three3 = 0;
        if(days[i]+1 <= days.back())
            one1 = costs[0]+dp(days, costs, one->second);
        else 
            one1 = costs[0] + dp(days, costs, days.size());
        if(days[i]+7 <= days.back())
            two2 = costs[1]+dp(days, costs, two->second);
        else 
            two2 = costs[1] + dp(days, costs, days.size());
        if(days[i]+30 <= days.back())
            three3 = costs[2]+dp(days, costs, three->second);
        else 
            three3 = costs[2] + dp(days, costs, days.size());
        ans = min({one1, two2, three3});
        return memo[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        for(int i = 0; i < n; i++)
            ds[days[i]] = i;
        memo = vector<int> (n, -1);
        return dp(days, costs, 0);
    }
};