class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<pair<int, int>> q;
        int ans = n+1;
        for(int i = 0; i < n; i++){
            q.push({i,0});
            vector<int> vis(n), parent(n);
            vis[i] = 1, parent[i] = -1;
            while(!q.empty()){
                auto u = q.front(); q.pop();
                int node = u.first, dist = u.second;
                // int node = u[0], par = u[1], dist = u[2];
                for(auto &nbr: adj[node]){
                    if(!vis[nbr]){
                        parent[nbr] = node;
                        q.push({nbr, dist+1});
                        vis[nbr] = dist+1;
                        // q.push({nbr, node, dist+1});
                    }else if(nbr != parent[node]){
                        ans = min(ans, vis[nbr]+dist+1);
                        break;
                    }
                }
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};
