class Solution {
public:
    int m;
    int n;
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) 
            return true;
        if (board.size() == 0 || board[0].size() == 0) 
            return false;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(board, word, 0, i, j))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) 
            return false;
        if (k == word.size() - 1) 
            return true; 
        char cur = board[i][j];
        board[i][j] = '*';  // used
        bool search_next = dfs(board, word, k+1, i-1 ,j) 
                        || dfs(board, word, k+1, i+1, j) 
                        || dfs(board, word, k+1, i, j-1)
                        || dfs(board, word, k+1, i, j+1);
        board[i][j] = cur;  // reset
        return search_next;
    }
};