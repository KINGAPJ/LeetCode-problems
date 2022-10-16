class Solution {
    vector<vector<int>> memo;
    const int inf = 1e9;
public:
    int dp(vector<int>& jd, int d, int i){
        int n = jd.size();
        if(i == n){
            if(d == 0)
                return 0;
            else return inf;
        }
        int &ret = memo[d][i];
        if(ret != inf)
            return ret;
        if(d == 1){
            return ret = *max_element(jd.begin()+i, jd.end());
        }
        int maxi = 0;
        for(int j = i; j < n; j++){
            maxi = max(maxi, jd[j]);
            ret = min(ret, maxi + dp(jd, d-1, j+1));
        }
        return ret;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        memo = vector<vector<int>> (d+1, vector<int>(n+1, inf));
        int ans = dp(jd, d, 0);
        return ans != inf ? ans : -1; 
    }
};