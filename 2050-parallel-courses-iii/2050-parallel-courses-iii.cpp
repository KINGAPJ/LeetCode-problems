class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> starts(n), inDeg(n);
        vector<vector<int>> adj(n);
        for(auto &i: relations){
            adj[i[0]-1].push_back(i[1]-1);
            inDeg[i[1]-1]++;
        }
        // for(int i = 0; i < n; i++){
        //     cout<<inDeg[i]<<' ';
        // }
        // cout<<'\n';
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0)
                q.push(i);
        }
        int ans = 0;
        while(!q.empty()){
            auto u = q.front(); q.pop();
            ans = max(ans, starts[u]+time[u]);
            for(auto &i: adj[u]){
                starts[i] = max(starts[i], starts[u]+time[u]);
                ans = max(ans, starts[i]+time[i]);
                if(--inDeg[i] == 0){
                    q.push(i);
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout<<starts[i]<<' ';
        // }
        // cout<<'\n';
        return ans;
    }
};