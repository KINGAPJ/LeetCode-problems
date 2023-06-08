class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        int i;
        for(i = 0; i < m; i++){
            if(grid[i][0] < 0){
                ans += (m-i)*n;
                break;
            }
        }
        i--;
        int j = 1;
        while(i >= 0){
            for(; j < n && grid[i][j] >= 0; j++);
            ans += n-j;
            i--;
        }
        return ans;
    }
};