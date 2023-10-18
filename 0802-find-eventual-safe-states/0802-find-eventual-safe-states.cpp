class Solution {
    vector<int> safe;
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis){
        if(safe[node] != -1)
            return safe[node];
        bool isSafe = true;
        vis[node] = 1;
        for(auto &i: adj[node]){
            if(vis[i] == 1){
                safe[i] = false;
                return safe[node] = false;
            }
            bool curr = dfs(i, adj, vis);
            isSafe = isSafe && curr;
        }
        vis[node] = 2;
        return safe[node] = isSafe;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        safe = vector<int>(n, -1);
        for(int i = 0; i < n; i++){
            if(graph[i].size() == 0)
                safe[i] = true;
        }
        vector<int> vis(n);
        for(int i = 0; i < n; i++){
            if(safe[i] == -1 && !vis[i])
                dfs(i, graph, vis);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safe[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};