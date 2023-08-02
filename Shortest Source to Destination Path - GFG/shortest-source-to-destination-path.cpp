//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int ds[5] = {0, -1, 0, 1, 0};
    int shortestDistance(int n, int m, vector<vector<int>> a, int x, int y) {
        // code here
        queue<pair<pair<int, int>, int>> q;
        if(a[0][0] == 1){
            q.push({{0, 0}, 0});
            a[0][0] = 2;
        }
        while(!q.empty()){
            auto u = q.front(); q.pop();
            int i = u.first.first, j = u.first.second, dist = u.second;
            if(i == x && j == y)
                return dist;
            for(int k = 0; k < 4; k++){
                int r = i+ds[k], c = j+ds[k+1];
                if(r >= 0 && r < n && c >= 0 && c < m && a[r][c] == 1){
                    a[r][c] = 2;
                    q.push({{r, c}, dist+1});
                }
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends