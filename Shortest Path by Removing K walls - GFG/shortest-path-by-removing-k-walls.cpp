//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int ds[5] = {0, 1, 0, -1, 0};
    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
  public:
    int shotestPath(vector<vector<int>>& grid, int n, int m, int k) {
        vector<vector<int>> vist(n, vector<int>(m, -1)); //for not going into TLE
        queue<vector<int>> q;
        q.push({0, 0, 0, k}); //x, y, dist, k
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int i = u[0], j = u[1];
            int dis = u[2], rem = u[3];
            if(!isValid(i, j, n, m))
                continue;
            if(i == n - 1 && j == m - 1)
                return dis;
            if(grid[i][j] == 1){
                if(rem > 0) rem--;
                else continue;
            }
            if(vist[i][j] != -1 && vist[i][j] >= rem)
                continue;
            vist[i][j] = rem;
            
            for(int l = 0; l < 4; l++){
                int r = i + ds[l], c = j + ds[l+1];
                q.push({r, c, dis+1, rem});
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends