//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<int> safe;
    bool dfs(int node, vector<int> adj[], vector<int> &vis){
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
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        safe = vector<int>(V, -1);
        for(int i = 0; i < V; i++){
            if(adj[i].size() == 0)
                safe[i] = true;
        }
        vector<int> vis(V);
        for(int i = 0; i < V; i++){
            if(safe[i] == -1 && !vis[i]){
                dfs(i, adj, vis);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(safe[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends