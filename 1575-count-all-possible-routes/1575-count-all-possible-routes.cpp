const int mod = 1e9 + 7;
class Solution {
    vector<vector<long>> dp;
    vector<int> locs;
    int st, fin;
    long f(int i, int fuel){
        if(fuel < 0)
            return 0;
        if(dp[i][fuel] != -1)
            return dp[i][fuel];
        int n = locs.size();
        long ans = (i == fin) ? 1 : 0;
        for(int j = 0; j < n; j++){
            if(j != i){
                ans = (ans + f(j, fuel - abs(locs[i] - locs[j]))) % mod;
            }
        }
        return dp[i][fuel] = ans;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        dp = vector(n, vector<long>(fuel+1, -1));
        locs = locations;
        st = start;
        fin = finish;
        return f(start, fuel);
    }
};