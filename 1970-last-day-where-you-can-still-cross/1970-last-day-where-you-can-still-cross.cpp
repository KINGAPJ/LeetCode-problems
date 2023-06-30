class Solution {
    int m, n;
    bool isv(int r, int c){return r >= 0 && r < m && c >= 0 && c < n;}
    int ds[5] = {0, -1, 0, 1, 0};
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = row, n = col;
        int lo = 1, hi = row*col;
        int ans = 1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            vector grid(row, vector<int>(col, 0));
            for(int i = 0; i < mid; i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            queue<pair<int, int>> q;
            for(int i = 0; i < col; i++){
                if(grid[0][i] == 0)
                    q.push({0, i});
            }
            bool yes = false;
            while(!q.empty()){
                auto [i, j] = q.front();
                q.pop();
                if(i == row-1){
                    yes = true;
                    break;
                }
                for(int k = 0; k < 4; k++){
                    int r = i+ds[k], c = j+ds[k+1];
                    if(isv(r, c) && grid[r][c] == 0){
                        grid[r][c] = 1;
                        q.push({r, c});
                    }
                }
            }
            if(yes){
                lo = mid + 1;
                ans = max(ans, mid);
            }else
                hi = mid - 1;
        }
        return ans;
    }
};