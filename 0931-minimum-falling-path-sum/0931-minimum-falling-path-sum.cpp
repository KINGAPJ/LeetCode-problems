class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = vector<int>(matrix[0].begin(), matrix[0].end());
        vector<int> curr(n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                curr[j] = matrix[i][j] + prev[j];
                for(int k = max(0, j-1); k <= min(n-1, j+1); k++)
                    curr[j] = min(curr[j], matrix[i][j] + prev[k]);
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};