/*
        2 cases:
                i am at node 0 or any arbitrary node:
                            0
                           /
                          1
        i: there may be an apple at 1.. so add 2 to path and check its subtree if further anyth needs to be added
        ii: there may not be an apple at 1.. so we check its subtree if further anyth needs to be added..
            if yes then add 2 + whatever that is
            if no then add nothing

*/
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
                int t = dfs(i);
                if(epulu[i] || t)
                    ret += 2 + t;
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