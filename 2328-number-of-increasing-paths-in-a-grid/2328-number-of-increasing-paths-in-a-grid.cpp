class Solution {
    vector<vector<int>> dp, grid;
    const int mod = 1e9 + 7;
public:
    int ds[5] = {0, -1, 0, 1, 0};
    bool isv(int i, int j){
        int m = grid.size(), n = grid[0].size();
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int f(int i, int j){
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 1;
        for(int k = 0; k < 4; k++){
            int r = i + ds[k], c = j + ds[k+1];
            if(isv(r, c) && grid[i][j] < grid[r][c]){
                ans = (ans + f(r, c))%mod;
            }
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp = vector (m, vector<int>(n, -1));
        this->grid = grid;
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = (ans + f(i, j)) % mod;
            }
        }
        return ans;
    }
};