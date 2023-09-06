//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    void dfs(int node, int& reach, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;
        reach++;
        for(auto &i: adj[node]){
            if(!vis[i])
                dfs(i, reach, adj, vis);
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[]){
	    // Code here
        vector<int> deg(V);
        for(int i = 0; i < V; i++){
            for(auto &j: adj[i])
                deg[j]++;
        }
        int numZeroIndeg = 0, zeroIndegVert = -1;
        for(int i = 0; i < V; i++){
            if(deg[i] == 0){
                if(numZeroIndeg > 0)
                    return -1;
                zeroIndegVert = i;
                numZeroIndeg++;
            }
        }
        int reach = 0;
        vector<bool> vis(V);
        if(numZeroIndeg == 1){
            dfs(zeroIndegVert, reach, adj, vis);
            if(reach != V)
                return -1;
        }
        vis = vector<bool> (V);
        int ans = -1;
        reach = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                ans = i;
                dfs(i, reach, adj, vis);
            }
        }
        if(reach == V){
            vis = vector<bool> (V);
            reach = 0;
            dfs(ans, reach, adj, vis);
            if(reach != V)
                return -1;
        }
        return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends