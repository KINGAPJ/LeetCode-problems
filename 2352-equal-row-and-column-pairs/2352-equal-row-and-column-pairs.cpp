class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        map<vector<int>, int> mp;
        for(int i = 0; i < m; i++){
            vector<int> rw;
            for(int j = 0; j < n; j++)
                rw.push_back(grid[i][j]);
            mp[rw]++;
        }
        int ans = 0;
        for(int j = 0; j < n; j++){
            vector<int> col;
            for(int i = 0; i < m; i++)
                col.push_back(grid[i][j]);
            if(mp.count(col))
                ans += mp[col];
        }
        return ans;
    }
};