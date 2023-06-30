class DSU{
    vector<vector<pair<int, int>>> par;
    vector<vector<int>> sz;
public:
    DSU(int row, int col){
        par = vector(row, vector<pair<int, int>>(col));
        sz = vector(row, vector<int>(col, 1));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                par[i][j] = {i, j};
                sz[i][j] = 1;
            }
        }
    }
    pair<int, int> find(pair<int, int> x){
        if(par[x.first][x.second] == x)
            return x;
        return par[x.first][x.second] = find(par[x.first][x.second]);
    }
    void join(pair<int, int> x, pair<int, int> y){
        auto a = find(x);
        auto b = find(y);
        if(a != b){
            if(sz[a.first][a.second] < sz[b.first][b.second]){
                swap(a, b);
            }
            par[b.first][b.second] = a;
            sz[a.first][a.second] += sz[b.first][b.second];
        }
    }
};
class Solution {
    int m, n;
    bool isv(int r, int c){return r >= 0 && r < m && c >= 0 && c < n;}
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = row+1, n = col;
        DSU dsu(row+1, col); //+1 for dummy 0 nodes
        vector grid(row+1, vector<int>(col));
        for(int i = 1; i < row+1; i++){
            dsu.join({0, 0}, {i, 0});
            dsu.join({0, col-1}, {i, col-1});
        }
        for(int i = 0; i < cells.size(); i++){
            grid[cells[i][0]][cells[i][1]-1] = 1;
            for(int k = 0; k < 8; k++){
                int r = cells[i][0] + dx[k], c = cells[i][1]-1 + dy[k];
                if(isv(r, c) && grid[r][c] == 1){
                    dsu.join({cells[i][0], cells[i][1]-1}, {r, c});
                }
                if(dsu.find({0, 0}) == dsu.find({0, col-1}))
                    return i;
            }
        }
        return cells.size();
    }
};