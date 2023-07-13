class Solution {
    vector<vector<int>> dp, clips;
    int time;
    int f(int i, int t){
        int n = clips.size();
        if(i == n){
            if(t >= time)
                return 0;
            else
                return 105;
        }
        if(t >= time)
            return 0;
        if(dp[i][t] != -1)
            return dp[i][t];
        int currbgn = clips[i][0], currend = clips[i][1];
        int ans = 105;
        if(t >= currbgn){
            ans = min(ans, 1+f(i+1, max(currend, t)));
            ans = min(ans, f(i+1, t));
        }
        return dp[i][t] = ans;
    }
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        if(clips.front()[0] != 0)
            return -1;
        int x = upper_bound(clips.begin(), clips.end(), vector<int>{0, 101}) - clips.begin();
        x--;
        int n = clips.size();
        dp = vector(n, vector<int>(101, -1));
        this->clips = clips;
        this->time = time;
        int ans = f(x, 0);
        return ans >= 105 ? -1 : ans;
    }
};