class Solution {
private:
    int di[8] = {1,1,1,0,0,-1,-1,-1};
    int dj[8] = {1,0,-1,1,-1,1,0,-1};
    bool isvalid(int i, int j, vector<vector<int>> &grid)
    {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==1)
            return false;
        grid[i][j] = 1;
        return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<vector<int>> q;
        if(isvalid(0,0,grid))q.push({0,0,1});
        grid[0][0] = 1;
        while(!q.empty())
        {
            auto v=q.front();
            q.pop();
            int i=v[0],j=v[1],currl=v[2];
            
            if(i==n-1 && j==n-1) return currl;
            for(int k = 0; k < 8; k++){
                int xx = i + di[k];
                int yy = j + dj[k];
                if(isvalid(xx, yy, grid))
                    q.push({xx, yy, currl + 1});
            }
        }
        return -1;
    }
};