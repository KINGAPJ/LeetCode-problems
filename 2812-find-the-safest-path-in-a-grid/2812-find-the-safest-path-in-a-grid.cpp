class Solution {
    int ds[5] = {0, -1, 0, 1, 0};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    q.push({{i, j}, 0});
                }else
                    grid[i][j] = -1;
            }
        }
        while(!q.empty()){
            auto u = q.front(); q.pop();
            int i = u.first.first, j = u.first.second, dis = u.second;
            for(int k = 0; k < 4; k++){
                int r = i+ds[k], c = j+ds[k+1];
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == -1){
                    grid[r][c] = dis + 1;
                    q.push({{r, c}, dis+1});
                }
            }
        }// q is empty
        int lo = 0, hi = 2*n+1;
        int ans = lo;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            bool possible = false;
            // set<pair<int, int>> s;
            vector s(n, vector<bool>(n));
            queue<pair<int, int>> q1;
            if(grid[0][0] >= mid && grid[n-1][n-1] >= mid){
                q1.push({0, 0});
                s[0][0] = true;
            }
            while(!q1.empty()){
                auto u = q1.front(); q1.pop();
                int i = u.first, j = u.second;
                if(i == n-1 && j == n-1){
                    possible = true;
                    break;
                }
                for(int k = 0; k < 4; k++){
                    int r = i+ds[k], c = j+ds[k+1];
                    if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] >= mid && !s[r][c]){
                        q1.push({r, c});
                        s[r][c] = true;
                    }
                }
            }
            if(possible){
                lo = mid + 1;
                ans = max(ans, mid);
            }else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};