class Solution {
public:
    bool dfs(vector<vector<int>>&grid, int i, int j, int& count){
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m || i < 0 || j < 0)
            return false;
        if(grid[i][j] != 1)
            return true;
        grid[i][j] = 2;
        count++;
        bool one = dfs(grid, i+1, j, count);
        bool two = dfs(grid, i, j+1, count);
        bool three = dfs(grid, i-1, j, count);
        bool four = dfs(grid, i, j-1, count);
        return (one && two && three && four);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0, count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                    if(dfs(grid, i, j, count))
                        ans += count;
                    count = 0;
            }
        }
        return ans;        
    }
};