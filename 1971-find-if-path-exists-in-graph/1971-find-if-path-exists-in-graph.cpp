class Solution {
    vector<vector<int>> adj;
    vector<bool> vis;
public:
    bool dfs(int s, int d){
        vis[s] = true;
        bool found = false;
        for(auto &i: adj[s]){
            if(!vis[i]){
                if(i == d)
                    return true;
                found |= dfs(i, d);
            }
        }
        return found;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj = vector<vector<int>>(n);
        vis = vector<bool>(n);
        if(source == destination)
            return true;
        if(edges.size() == 0)
            return false;
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return dfs(source, destination);
    }
};