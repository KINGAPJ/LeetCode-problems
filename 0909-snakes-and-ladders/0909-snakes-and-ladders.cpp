class Solution {
public:
    pair<int, int> rowcol(int n, int s){ //{row, col}
        int row = (n - 1) - (s - 1)/n;
        int col = (((s - 1)/n & 1) == 0) ? (s - 1)% n : (n - 1) - (s - 1)% n;
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n*n + 1);
        queue<vector<int>> q;
        q.push({1, 0});
        vis[1] = true;
        while(!q.empty()){
            auto u = q.front();
            int s = u[0], moves = u[1];
            q.pop();
            if(s == n*n)
                return moves;
            for(int i = 1; i <= 6 && (s + i) <= n*n; i++){
                auto rc = rowcol(n, s + i);
                int row = rc.first, col = rc.second;
                int next = (board[row][col] == -1) ? (s + i) : (board[row][col]);
                if(!vis[next])
                    q.push({next, moves + 1});
                vis[next] = true;
            }
        }
        return -1;
    }
};