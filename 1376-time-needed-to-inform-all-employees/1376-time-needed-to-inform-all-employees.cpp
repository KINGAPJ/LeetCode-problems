class Solution {
public:
    int dfs(int emp, vector<vector<int>> &adj, vector<int>& time){
        if(time[emp] == 0)
            return 0;
        int mxtime = 0;
        for(auto &i: adj[emp]){
            mxtime = max(time[emp] + dfs(i, adj, time), mxtime);
        }
        return mxtime;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1)
            return 0;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        return dfs(headID, adj, informTime);
    }
};