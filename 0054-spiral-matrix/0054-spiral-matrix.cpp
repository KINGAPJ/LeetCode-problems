class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int beg_row = 0, beg_col = 0;
        int end_row = m-1, end_col = n-1;
        int num = m * n;
        int count = 0;
        vector<int> ans;
        while(count < num){
            for(int i = beg_col; i <= end_col && count < num; i++){
                ans.push_back(matrix[beg_row][i]);
                count++;
            }
            beg_row++;
            for(int i = beg_row; i <= end_row && count < num; i++){
                ans.push_back(matrix[i][end_col]);   
                count++;
            }
            end_col--;
            for(int i = end_col; i >= beg_col && count < num; i--){
                ans.push_back(matrix[end_row][i]);   
                count++;
            }
            end_row--;
            for(int i = end_row; i >= beg_row && count < num; i--){
                ans.push_back(matrix[i][beg_col]);   
                count++;
            }
            beg_col++;
        }
        return ans;
    }
};