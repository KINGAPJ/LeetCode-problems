class Solution {
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<bool> epulu;
public:
    int dfs(int node){
        vis[node] = true;
        int ret = 0;
        for(auto &i: adj[node]){
            if(!vis[i]){
                if(epulu[i]){
                    ret += 2 + dfs(i);
                }else{
                    int t = dfs(i);
                    if(t)
                        ret += 2 + t;
                }
            }
        }
        return ret;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj = vector<vector<int>> (n);
        vis = vector<bool> (n);
        epulu = hasApple;
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return dfs(0);
    }
};