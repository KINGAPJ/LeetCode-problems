//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution {
  public:
    /*
    Observation: how can we use bitmask dp here:
    suppose we made a graph with some i-1 arbitrary nodes.. 
    we now know, every single node can contribute to an answer..
    it wont contribute only when a particular edge is required but not available..
    
    so, we use this to form a dp:
    dp[curr][subset] = dp[curr][subset] + dp[prev][subset without the prev node]..
    where prev-curr is an edge.. 
    prev are all nodes which are already existing..
    curr is the new node which we are trying..
    */
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        // we need to check if an edge exists.. for this adjacency matrix 
        bool adj[N][N]; memset(adj, false, sizeof(adj));
        for(auto &i: graph){
            adj[i[0]-1][i[1]-1] = true;
            adj[i[1]-1][i[0]-1] = true;
        }
        ll dp[N][1<<N]; memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++)
            dp[i][1<<i] = 1; //single nodes always have the potential
            
        for(int subset = 0; subset < (1<<N); subset++){ //from single node to all nodes
        //now we try for this new subset
        
            for(int curr = 0; curr < N; curr++){
                if(!(subset & (1<<curr))) //if curr node is not part of the new subset
                    continue;
                for(int prev = 0; prev < N; prev++){
                    if(curr == prev || arr[curr] == arr[prev]) //skip if current node is same as previous node
                        continue;
                    if(!(subset & (1<<prev))) //if prev node is not part of the new subset
                        continue;
                    if(!adj[arr[prev]-1][arr[curr]-1]) //if there is no edge, then it doesnt contribute to ans
                        continue;
                    dp[curr][subset] += dp[prev][subset^(1<<curr)]; //the recurrence relation
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < N; i++) //final ans is formed graph using every node as lastly added node
            ans += dp[i][(1<<N)-1];
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends