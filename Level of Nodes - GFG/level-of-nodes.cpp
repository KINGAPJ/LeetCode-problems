//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X){
	    // code here
	    queue<int> q;
	    vector<bool> vis(V);
	    q.push(0);
	    vis[0] = true;
	    int ans = 0;
	    while(!q.empty()){
	        int n = q.size();
	        while(n--){
    	        auto u = q.front();
    	        q.pop();
	            if(u == X){
	                return ans;
	            }
	            for(auto &i: adj[u]){
	                if(!vis[i]){
	                    vis[i] = true;
	                    q.push(i);
	                }
	            }
	        }
	        ans++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends