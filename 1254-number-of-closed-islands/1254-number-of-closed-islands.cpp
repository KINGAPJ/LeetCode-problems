class Solution {
public:
    bool dfs(vector<vector<int>>&grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 2)
            return true;
        if((i == n - 1 || j == m - 1 || i == 0 || j == 0) && grid[i][j] == 0)
            return false;
        if(grid[i][j] == 1)
            return true;
        grid[i][j] = 2;
        bool one = dfs(grid, i+1, j);
        bool two = dfs(grid, i, j+1);
        bool three = dfs(grid, i-1, j);
        bool four = dfs(grid, i, j-1);
        return (one && two && three && four);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0)
                    ans += dfs(grid, i, j);
            }
        }
        return ans;
    }
};