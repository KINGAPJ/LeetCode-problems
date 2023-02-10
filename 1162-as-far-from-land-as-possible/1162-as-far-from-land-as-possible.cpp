class Solution {
public:
    int inf = 1e6;
    int di[4] = {0, 0, -1, 1}; //l, r, u, d
    int dj[4] = {-1, 1, 0, 0};
    bool inbounds(int i, int j, int n){
        if(i >= 0 && j >= 0 && i < n && j < n)
            return true;
        else return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, inf));
        queue<pair<int,int>> q;
        int levels = 0, currlvl = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    q.push({i,j});
                    currlvl++;
                }
            }
        }
        if(q.size() == n*n or q.empty())
            return -1;
        int nxtlvl = 0;
        while(!q.empty()){
            if(currlvl == 0){
                levels++;
                currlvl = nxtlvl;
                nxtlvl = 0;
            }
            auto x = q.front();
            q.pop();
            currlvl--;
            for(int i = 0; i < 4; i++){
                int xx = x.first + di[i];
                int yy = x.second + dj[i];
                if(inbounds(xx, yy, n) && grid[xx][yy] == 0){
                    q.push({xx, yy});
                    nxtlvl++;
                    grid[xx][yy] = 1;
                }
            }
        }
        return levels;
        // for(int i1 = 0; i1 < n; i1++){
        //     for(int j1 = 0; j1 < n; j1++){
        //         for(int i2 = 0; i2 < n; i2++){
        //             for(int j2 = 0; j2 < n; j2++){
        //                 if(grid[i1][j1] == 0 || grid[i2][j2] == 1)
        //                     continue;
        //                 dist[i2][j2] = min(dist[i2][j2], abs(i2 - i1) + abs(j2 - j1));
        //             }
        //         }
        //     }
        // }
        // int ans = 0, minus1 = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(dist[i][j] != inf)
        //             ans = max(ans, dist[i][j]);
        //         minus1 += grid[i][j];
        //     }
        // }
        // if(!minus1 or minus1 == n*n)
        //     return -1;
        // return ans;
    }
};