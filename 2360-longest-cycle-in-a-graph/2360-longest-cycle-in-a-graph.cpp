class Solution {
    vector<vector<int>> adj;
    vector<int> par;
    vector<bool> vis;
    int ans = 0;
public:
    void dfs(int node){
        vis[node] = true;
        for(auto &i: adj[node]){
            par[i] = node;
            if(!vis[i])
                dfs(i);
            else{
                int currans = 2;
                int currpar = par[node];
                if(currpar != -1){
                    while(currpar != i){
                        currpar = par[currpar];
                        if(currpar == -1)
                            return;
                        currans++;
                    }
                    ans = max(currans, ans);
                }
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        adj = vector<vector<int>>(n);
        par = vector<int>(n, -1);
        vis = vector<bool>(n);
        for(int i = 0; i < n; i++){
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(i);
        }
        return ans > 1 ? ans : -1;
    }
};