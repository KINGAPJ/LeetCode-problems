class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        if(vis[node])
            return;
        int n = adj.size();
        vis[node] = true;
        for(int i = 0; i < n; i++){
            if(adj[node][i] == 1 && !vis[i])
                dfs(i, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        return ans;
    }
};