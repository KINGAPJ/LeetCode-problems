class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int dp[26] = {0};
        int curr = 1;
        dp[s[0]-'a'] = 1;
        int ans = curr;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]+1 || s[i-1] == 'z' && s[i] == 'a')
                curr++;
            else
                curr = 1;
            if(dp[s[i]-'a'] < curr){
                ans += curr - dp[s[i]-'a'];
                dp[s[i]-'a'] = curr;
            }
        }
        return ans;
    }
};