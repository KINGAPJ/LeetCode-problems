class Solution {
    int m, n;
    bool isv(int r, int c){return r >= 0 && r < m && c >= 0 && c < n;}
    int ds[5] = {0, -1, 0, 1, 0};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        m = grid.size(), n = grid[0].size();
        map<int, set<pair<int, int>>> seen;
        set<char> keyS;
        set<char> lockS;
        int keymask = 0;
        int stR = -1, stC = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char cell = grid[i][j];
                if(cell >= 'a' && cell <= 'f'){
                    keymask += (1 << (cell - 'a'));
                    keyS.insert(cell);
                }
                if(cell >= 'A' && cell <= 'F'){
                    lockS.insert(cell);
                }
                if(cell == '@'){
                    stR = i;
                    stC = j;
                }
            }
        }
        queue<vector<int>> q;
        q.push({stR, stC, 0, 0});
        seen[0].insert({stR, stC});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int curR = cur[0], curC = cur[1], keys = cur[2], dist = cur[3];
            for(int k = 0; k < 4; k++){
                int newR = curR + ds[k], newC = curC + ds[k+1];
                if(isv(newR, newC) && grid[newR][newC] != '#'){
                    char cell = grid[newR][newC];
                    if(keyS.count(cell)){
                        if(((1 << (cell - 'a')) & keys) != 0)
                            continue;
                        int newK = (keys | (1 << (cell - 'a')));
                        if(newK == keymask)
                            return dist + 1;
                        seen[newK].insert({newR, newC});
                        q.push({newR, newC, newK, dist+1});
                    }
                    if(lockS.count(cell) && ((keys & (1 << (cell - 'A')))) == 0)
                        continue;
                    else if(!seen[keys].count({newR, newC})){
                        seen[keys].insert({newR, newC});
                        q.push({newR, newC, keys, dist+1});
                    }
                }
            }
        }
        return -1;
    }
};