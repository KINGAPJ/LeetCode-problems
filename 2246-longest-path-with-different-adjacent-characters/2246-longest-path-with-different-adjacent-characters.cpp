class Solution {
    vector<vector<int>> adj;
    vector<bool> vis;
    int ans = 1;
public:
    // void dfs(int node, int currdist){
    //     vis[node] = true;
    //     ans = max(ans, currdist);
    //     for(auto &i: adj[node]){
    //         if(!vis[i])
    //             dfs(i, currdist+1);
    //     }
    // }
    int dfs(int curr, int& ans)
    {
        int maxh = 0, smaxh = 0;
        vis[curr] = 1;
        for(auto&x : adj[curr])
        {
            if(!vis[x])
            {
                int temp = dfs(x,ans);
                if(temp>maxh)
                {
                    smaxh = maxh;
                    maxh = temp;
                }
                else if(temp>smaxh)
                {
                    smaxh = temp;
                }
            }
        }
        ans = max(maxh + smaxh + 1,ans);
        return 1 + maxh;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        adj = vector<vector<int>>(n);
        vis = vector<bool>(n);
        vector<int> deg(n);
        for(int i = 1; i < n; i++){
            if(s[parent[i]] != s[i]){
                adj[parent[i]].push_back(i);
                adj[i].push_back(parent[i]);
                deg[parent[i]]++;
                deg[i]++;
            }
        }
        // for(int i = 0; i < n; i++){
        //     if(deg[i] == 1 && !vis[i])
        //         dfs(i, 1);
        // }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans = max(ans,dfs(i,ans));
            }
        }
        return ans;
    }
};