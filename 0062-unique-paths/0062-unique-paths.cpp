class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        vector<vector<int>> arr(m, vector<int>(n));
        for(i = 0; i < m; i++){
            arr[i][0] = 1;
        }
        for(j = 0; j < n; j++){
            arr[0][j] = 1;
        }
        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++){
                arr[i][j] = arr[i][j-1] + arr[i-1][j];
            }
        }
        return arr[m-1][n-1];
    }
};