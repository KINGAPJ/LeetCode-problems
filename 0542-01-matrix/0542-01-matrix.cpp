class Solution {
public:
    int ds[5] = {0, -1, 0, 1, 0};
    bool isv(int i, int j, int n, int m){
        return (i >= 0 && j >= 0 && i < n && j < m);}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<vector<int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto w = q.front();
            q.pop();
            for(int k = 1; k < 5; k++){
                int xx = w[0] + ds[k], yy = w[1] + ds[k-1];
                if(isv(xx, yy, n, m) && dist[xx][yy] == -1){
                    q.push({xx, yy});
                    dist[xx][yy] = dist[w[0]][w[1]] + 1;
                }
            }
        }
        return dist;
    }
};