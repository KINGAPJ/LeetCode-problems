class Solution {
public:
    int ds[5] = {0, -1, 0, 1, 0};
    bool isvalid(int i, int j, int m, int n){
        return((i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1));}
    bool isborder(int i, int j, int m, int n){
        return((i <= 0 || j <= 0 || i >= m - 1 || j >= n - 1));}
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>> q;
        maze[ent[0]][ent[1]] = '+';
        q.push({ent[0], ent[1], 0});
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(int k = 1; k < 5; k++){
                int r = u[0] + ds[k], c = u[1] + ds[k-1], currd = u[2];
                if(!isborder(r, c, m, n) && maze[r][c] == '.'){
                    q.push({r, c, currd+1});
                    maze[r][c] = '+';
                }else if(isvalid(r, c, m, n) && maze[r][c] == '.')
                    return currd + 1;
            }
        }
        return -1;
    }
    // , vector<int>& ent
     // && !(i == ent[0] && j == ent[1]
};