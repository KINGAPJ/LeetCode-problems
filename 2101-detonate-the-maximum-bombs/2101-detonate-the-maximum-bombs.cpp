class Solution {
    vector<vector<int>> adj;
    unordered_set<int> vis;
public:
    void dfs(int node){
        vis.insert(node);
        for(auto &i: adj[node]){
            if(!vis.count(i))
                dfs(i);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        adj = vector<vector<int>>(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                if( (0LL+bombs[i][0]-bombs[j][0])*(0LL+bombs[i][0]-bombs[j][0]) + 
                    (0LL+bombs[i][1]-bombs[j][1])*(0LL+bombs[i][1]-bombs[j][1])
                        <= 1LL*bombs[i][2]*bombs[i][2]
                  ){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            vis.clear();
            dfs(i);
            ans = max(ans, (int)vis.size());
        }
        return ans;
    }
};