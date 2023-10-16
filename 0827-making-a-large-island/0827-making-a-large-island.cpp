class Solution{
    int ds[5] = {0, -1, 0, 1, 0};
    struct DSU{
        map<pair<int, int>, pair<int, int>> par;
        map<pair<int, int>, int> size;
        pair<int, int> findPar(pair<int, int> v){
            if(par.count(v) == 0 || par[v] == v)
                return par[v] = v;
            return par[v] = findPar(par[v]);
        }
        void unionSize(pair<int, int> a, pair<int, int> b){
            a = findPar(a);
            b = findPar(b);
            if(a != b){
                if(size[a] < size[b])
                    swap(a, b);
                par[b] = a;
                size[a] += size[b];
            }   
        }
    };
    void dfs(int x, int y, vector<vector<int>>& grid, pair<int, int> par, DSU &dsu){
        int n = grid.size();
        grid[x][y] = 2;
        dsu.unionSize({x, y}, par);
        for(int k = 0; k < 4; k++){
            int r = x + ds[k], c = y + ds[k+1];
            if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1){
                if(!dsu.size.count({r, c}))
                    dsu.size[{r, c}] = 1;
                dfs(r, c, grid, par, dsu);
            }
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid){
        // Your code goes here.
        DSU dsu;
        int n = grid.size();
        bool yes = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    yes = true;
                    if(!dsu.size.count({i, j}))
                        dsu.size[{i, j}] = 1;
                    dfs(i, j, grid, {i, j}, dsu);
                }
            }
        }
        if(!yes)
            return 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int curr = 0;
                    set<pair<int, int>> pars;
                    for(int k = 0; k < 4; k++){
                        int r = i + ds[k], c = j + ds[k+1];
                        auto par = dsu.findPar({r, c});
                        if(r >= 0 && r < n && c >= 0 && c < n && !pars.count(par)){
                            curr += dsu.size[par];
                            pars.insert(par);
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        return ans == 0 ? n*n : ans+1;
    }
};