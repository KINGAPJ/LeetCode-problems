//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{
    vector<vector<int>> adj;
    vector<int> vis;
    vector<int> par;
    ll ans = 0;
  public:
    void dfs(int node){
        vis[node] = 1;
        for(auto &i: adj[node]){
            if(!vis[i]){
                par[i] = node;
                dfs(i);
            }else if(vis[i] == 1){
                int curPar = par[node];
                ll size = node;
                while(curPar != i){
                    size += curPar;
                    curPar = par[curPar];
                }
                size += curPar;
                // int curPar = par[node];
                // ll size = node;
                // cout<<node<<'\n'<<curPar;
                // while(curPar != -1){
                //     size += curPar;
                //     curPar = par[curPar];
                //     // cout<<'\n'<<curPar;
                // }
                ans = max(ans, size);
            }
        }
        vis[node] = 2;
    }
    long long largestSumCycle(int n, vector<int> edge){
    // code here
        adj = vector<vector<int>>(n);
        vis = vector<int>(n);
        par = vector<int>(n, -1);
        for(int i = 0; i < n; i++)
            if(edge[i] != -1)
                adj[i].push_back(edge[i]);
        // for(int i = 0; i < n; i++){
        //     cout<<i<<": ";
        //     for(auto &j: adj[i])
        //         cout<<j<<" ";
        //     cout<<'\n';
        // }
        for(int i = 0; i < n; i++)
            if(!vis[i])
                dfs(i);
        return ans != 0 ? ans : -1;
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends