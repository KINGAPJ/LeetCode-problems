class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i == m)
            return j;
        if(grid[i][j] == 1){
            if(j == n-1)
                return -1;
            if(grid[i][j+1] == grid[i][j])
                return dfs(grid, i+1, j+1);
            else return -1;
        }else{
            if(j == 0)
                return -1;
            if(grid[i][j-1] == grid[i][j])
                return dfs(grid, i+1, j-1);
            else return -1;
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n);
        for(int j = 0; j < n; j++){
            ans[j] = dfs(grid, 0, j);
        }
        return ans;
    }
};