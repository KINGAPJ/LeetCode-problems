class Solution {
public:
    int ds[5] = {0, 1, 0, -1, 0};
    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vist(m, vector<int>(n, -1)); //for not going into TLE
        queue<vector<int>> q;
        q.push({0, 0, 0, k}); //x, y, dist, k
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int i = u[0], j = u[1];
            int dis = u[2], rem = u[3];
            if(!isValid(i, j, m, n))
                continue;
            if(i == m - 1 && j == n - 1)
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