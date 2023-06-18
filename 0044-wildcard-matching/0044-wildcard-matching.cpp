class Solution {
    string s, p;
    vector<vector<int>> dp;
public:
    int f(int si, int pi){
        int n = s.size(), m = p.size();
        if(si == n){
            if(pi == m)
                return true;
            int i = pi;
            while(i < m){
                if(p[i++] != '*')
                    return false;
            }
            return true;
        }
        if(dp[si][pi] != -1)
            return dp[si][pi];
        bool ret = false;
        if(p[pi] != '?' && p[pi] != '*'){
            if(s[si] == p[pi])
                ret |= f(si+1, pi+1);
            else return false;
        }else if(p[pi] == '?'){
            ret |= f(si+1, pi+1);
        }else{
            for(int i = si; i <= n; i++){
                ret |= f(i, pi+1);
            }
        }
        return dp[si][pi] = ret;
    }
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        int n = s.size(), m = p.size();
        dp = vector(n+1, vector<int>(m+1, -1));
        return f(0, 0);
    }
};