//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    vector<vector<vector<int>>> adj; //adj[u] = {v, w}
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        adj = vector<vector<vector<int>>>(n+1);
        for(auto &i: flights)
            adj[i[0]].push_back(vector<int>{i[1], i[2]});
        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;
        set<vector<int>> heap;
        heap.insert({0, k});
        while(!heap.empty()){
            auto x = *(heap.begin());
            heap.erase(x);
            int u = x[1];
            for(auto &i: adj[u]){
                int v = i[0], w = i[1];
                if(w + dis[u] < dis[v]){
                    heap.erase({dis[v], v});
                    dis[v] = w + dis[u];
                    heap.insert({dis[v], v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < dis.size(); i++)
                ans = max(ans, dis[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends