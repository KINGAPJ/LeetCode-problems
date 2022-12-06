//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int ds[5] = {0, -1, 0, 1, 0};
    bool isv(int i, int j, int n, int m){
        return i < n && i >= 0 && j < m && j >= 0;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    queue<vector<int>> q;
	    vector<vector<int>> mat(n, vector<int>(m));
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < m; j++)
	            if(grid[i][j] == 1)
	                q.push({i, j, 0}), mat[i][j] = 0;
        
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int d = u[2];
            for(int k = 0; k < 4; k++){
                int r = u[0] + ds[k], c = u[1] + ds[k+1];
                if(isv(r, c, n, m) && grid[r][c] == 0){
                    q.push({r, c, d+1});
                    mat[r][c] = d+1;
                    grid[r][c] = 1;
                }
            }
        }
        return mat;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends