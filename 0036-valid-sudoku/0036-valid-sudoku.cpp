class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> h(9), v(9), b(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int temp = board[i][j];
                    if(h[i].count(temp) || v[j].count(temp) || b[(i/3)*3 + j/3].count(temp))
                        return false;
                    h[i].insert(temp);
                    v[j].insert(temp);
                    b[(i/3)*3 + j/3].insert(temp);
                }
            }
        }
        return true;
    }
};