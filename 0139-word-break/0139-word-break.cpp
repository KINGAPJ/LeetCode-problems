class Solution {
    unordered_set<string> st;
    string s;
    vector<int> dp;
    bool f(int i){
        int n = s.size();
        if(i == n){
            return true;
        }
        string curr = "";
        if(dp[i] != -1)
            return dp[i];
        bool ans = false;
        for(int j = i; j < n; j++){
            curr.push_back(s[j]);
            if(st.count(curr)){
                ans |= f(j+1);
            }
        }
        return dp[i] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        int n = s.size();
        for(auto &i: wordDict)
            st.insert(i);
        dp = vector<int>(n, -1);
        return f(0);
    }
};