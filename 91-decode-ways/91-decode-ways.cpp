class Solution {
public:
    int memo[101];
    int dp(string s, int i, int n){
        if (s[i] == '0') //discard the combination as 02... isnt valid
            return 0;
        if (i >= n-1)
            return 1;
        if (memo[i] != -1)
            return memo[i];
        int x = (s[i] - '0'), y = (s[i+1] - '0');
        int num = 10*x + y;
        if(num <= 26){
            return memo[i] = (dp(s, i+1, n) + dp(s, i+2, n));// 12..: 1, 2.. amd 12, ..
        }
        else
            return memo[i] = dp(s, i+1, n); 
        //29.. will only take 2, then 9..; 32.. 3, 2..
        
    }
    int numDecodings(string s) {
        memset(memo, -1, sizeof(memo));
        return dp(s, 0, s.length());
    }
};