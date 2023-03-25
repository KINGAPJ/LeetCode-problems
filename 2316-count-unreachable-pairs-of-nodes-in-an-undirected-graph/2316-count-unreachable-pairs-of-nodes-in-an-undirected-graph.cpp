class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<long long> numCon;
    long long con = 0;
    void dfs(int node){
        if(!vis[node])
            con++;
        vis[node] = true;
        for(auto i: adj[node]){
            if(!vis[i])
                dfs(i);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n, false);
        long long ans = 0;
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < n; i++){
            con = 0;
            dfs(i);
            numCon.push_back(con);
        }
        // for(auto i: numCon){
        //     cout<<i<<' ';
        // }cout<<endl;
        long long s = numCon.size();
        vector<long long> pref(s);
        pref[0] = numCon[0];
        for(long long i = 1; i < s; i++){
            pref[i] = pref[i-1] + numCon[i];
        }
        for(long long i = s - 1; i > 0; i--){
            ans += (numCon[i] * pref[i-1]);
        }
        return ans;
    }
};
