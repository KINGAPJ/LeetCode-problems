class Solution {
    vector<bool> vis;
    vector<vector<vector<int>>> adj;
    int ans = INT_MAX;
public:
    void dfs(int node){
        if(!vis[node])
            vis[node] = true;
        for(auto &i: adj[node]){
            ans = min(ans, i[1]);
            if(!vis[i[0]]){
                dfs(i[0]);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        adj = vector<vector<vector<int>>> (n+1);
        vis = vector<bool> (n+1);
        for(auto &i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        dfs(1);
        return ans;
    }
};