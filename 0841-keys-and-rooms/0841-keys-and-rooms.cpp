class Solution {
public:
    //simply traverse all the edges
    void dfs(int node, vector<vector<int>> &adj, vector<int>& vis){
        vis[node] = 1;
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n);
        dfs(0, rooms, vis);
        for(auto x: vis){
            if (x == 0)
                return false;
        }
        return true;
    }
};