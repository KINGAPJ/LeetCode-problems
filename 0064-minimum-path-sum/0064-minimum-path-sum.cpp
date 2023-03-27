class Solution {
public:
    //iterative dp
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i && !j)
                    grid[i][j] += grid[i-1][j];
                if(!i && j)
                    grid[i][j] += grid[i][j-1];
                if(i && j)
                    grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[n-1][m-1];
    }
};