//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int, int>>> adj(n);
        for(auto &i: edges){
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        set<pair<int, int>> pq;
        pq.insert({0, 0});
        while(!pq.empty()){
            auto u = *(pq.begin());
            pq.erase(u);
            for(auto &i: adj[u.second]){
                if(dist[u.second] + i.second < dist[i.first]){
                    pq.erase({dist[i.first], i.first});
                    dist[i.first] = dist[u.second] + i.second;
                    pq.insert({dist[i.first], i.first});
                }
            }
        }
        vector<int> ans;
        for(auto &i: dist){
            if(i == INT_MAX)
                ans.push_back(-1);
            else ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends