class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long n = grid.size(), m = grid[0].size();
        vector pref(n, vector<long long>(m, 1));
        vector suff(n, vector<long long>(m, 1));
        vector ans(n, vector<int>(m, 1));
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                if(i == 0 && j == 0)
                    continue;
                long long prevI = -1, prevJ = -1;
                if(j == 0){
                    prevJ = m-1; prevI = i-1;
                }else{
                    prevJ = j-1; prevI = i;
                }
                pref[i][j] = (1LL*grid[prevI][prevJ] * pref[prevI][prevJ]) % 12345;
            }
        }
        for(long long i = n-1; i >= 0; i--){
            for(long long j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1)
                    continue;
                long long nextI = n+1, nextJ = m+1;
                if(j == m-1){
                    nextJ = 0; nextI = i+1;
                }else{
                    nextJ = j+1; nextI = i;
                }
                suff[i][j] = (1LL*grid[nextI][nextJ] * suff[nextI][nextJ]) % 12345;
            }
        }
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                ans[i][j] = (pref[i][j] * suff[i][j]) % 12345;
            }
        }
        return ans;
    }
};