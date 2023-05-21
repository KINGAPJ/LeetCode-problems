class Solution {
public:
    int ds[5] = {0, -1, 0, 1, 0};
    queue<vector<int>> q;
    bool isv(int i, int j, int n){
        return(i >= 0 && j >= 0 && i < n && j < n);}
    void dfspaint(int i, int j, vector<vector<int>> &grid){
        int n = grid.size();
        grid[i][j] = 2;
        q.push({i,j,2});
        for(int k = 1; k < 5; k++){
            int r = i + ds[k], c = j + ds[k-1];
            if(isv(r, c, n) && grid[r][c] == 1){
                dfspaint(r, c, grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool paint = false;
        for(int i = 0; i < n; i++){
            if(paint)
                break;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !paint){
                    dfspaint(i, j, grid);
                    paint = true;
                }
            }
        }
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(int k = 1; k < 5; k++){
                int r = u[0] + ds[k], c = u[1] + ds[k-1], currd = u[2];
                if(isv(r, c, n)){
                    if(grid[r][c] == 0){
                        q.push({r, c, currd + 1});
                        grid[r][c] = currd + 1;
                    }else if(grid[r][c] == 1)
                        return currd - 2;
                }
            }
        }
        return n;
    }
};