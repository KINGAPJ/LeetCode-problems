class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        for(auto &i: roads){
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                int curr = adj[i].size()+adj[j].size()-adj[i].count(j);
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};