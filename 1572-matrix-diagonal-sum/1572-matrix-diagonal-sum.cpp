class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), ans = 0;
        for(int i = 0; i < n; i++){
            if(i != n-1-i)
                ans += mat[i][i] + mat[i][n-1-i];
            else ans += mat[i][i];
        }
        return ans;
    }
};