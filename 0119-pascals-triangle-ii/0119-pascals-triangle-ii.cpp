class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            return {1};
        }
        vector<vector<int>> rows(2, vector<int>(rowIndex+1));
        rows[0][0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            rows[1][0] = 1;
            for(int j = 1; j <= i; j++)
                rows[1][j] = rows[0][j-1] + rows[0][j];
            rows[0] = rows[1];
        }
        return rows[0];
    }
};