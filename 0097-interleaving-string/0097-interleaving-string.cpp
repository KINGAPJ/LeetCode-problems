class Solution {
    string s1, s2, s3;
    int dp[201][101][101];
    bool f(int s3i, int s1i, int s2i){
        int m = s3.size(), n1 = s1.size(), n2 = s2.size();
        if(s1i == n1 && s2i == n2){
            if(s3i == m)
                return true;
            return false;
        }
        if(s3i == m)
            return false;
        if(dp[s3i][s1i][s2i] != -1)
            return dp[s3i][s1i][s2i];
        bool ret = false;
        if(s1i < n1 && s1[s1i] == s3[s3i]){
            ret |= f(s3i+1, s1i+1, s2i);
        }
        if(s2i < n2 && s2[s2i] == s3[s3i]){
            ret |= f(s3i+1, s1i, s2i+1);
        }
        return dp[s3i][s1i][s2i] = ret;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0);
    }
};