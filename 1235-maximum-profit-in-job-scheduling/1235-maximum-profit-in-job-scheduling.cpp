class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
        /*
        vector<vector<int>> v(n), profs(n);
        for(int i = 0; i < n; i++){
            v[i] = {endTime[i], startTime[i], profit[i]};
            // profs[i] = {profit[i], startTime[i], endTime[i]};
        }
        sort(v.begin(), v.end());
        vector<int> dp(n), maxs(n);
        dp[0] = v[0][2];
        maxs[0] = v[0][2];
        for(int i = 1; i < n; i++){
            int j = (upper_bound(v.begin(), v.end(), vector<int>{v[i][1], INT_MAX, INT_MAX}) - v.begin()) - 1;
            cout<<"j: "<<j<<endl;
            if(j >= 0 && j < i){
                dp[i] = dp[j] + v[i][2];
            }else
                dp[i] = v[i][2];
            maxs[i] = max(maxs[i-1], dp[i]);
            for(auto &x: dp)
                cout<<x<<" ";
            cout<<endl;
            for(auto &x: maxs)
                cout<<x<<" ";
            cout<<endl<<endl;
        }
        return maxs[n-1];*/
    }
};
/*
[4,2,4,8,2]
[5,5,5,10,8]
[1,2,8,10,4]
*/