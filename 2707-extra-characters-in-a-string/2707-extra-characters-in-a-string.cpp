class Solution {
    set<string> dict;
    string s;
    vector<int> dp;
public:
    int f(int i){
        int n = s.size();
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = n;
        string curr = "";
        for(int j = i; j < n; j++){
            curr.push_back(s[j]);
            int opt1 = (dict.count(curr)) ? f(j+1) : curr.size() + f(j+1);
            ans = min(opt1, ans);
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        dict = set<string>(dictionary.begin(), dictionary.end());
        int n = s.size();
        this->s = s;
        dp = vector<int>(n, -1);
        return f(0);
    }
};