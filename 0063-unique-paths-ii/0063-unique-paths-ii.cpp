class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int i, j;
        int m = arr.size();
        int n = arr[0].size();
        if(arr[m-1][n-1] == 1) return 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(arr[i][j] == 1)
                    arr[i][j] = -1;
            }
        }
        for(i = 0; i < m; i++){
            if(arr[i][0] == -1)
                break;
            arr[i][0] = 1;
        }
        for(j = 0; j < n; j++){
            if(arr[0][j] == -1)
                break;
            arr[0][j] = 1;
        }
        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++){
                if(arr[i][j] != -1){
                    if(arr[i-1][j] == -1 && arr[i][j-1] != -1)
                        arr[i][j] = arr[i][j-1];
                    else if(arr[i-1][j] != -1 && arr[i][j-1] == -1)
                        arr[i][j] = arr[i-1][j];
                    else if(arr[i-1][j] == -1 && arr[i][j-1] == -1)
                        arr[i][j] = 0;
                    else arr[i][j] = arr[i-1][j] + arr[i][j-1];
                }
            }
        }
        return arr[m-1][n-1];
    }
};