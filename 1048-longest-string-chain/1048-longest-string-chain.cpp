class Solution {
    unordered_map<string, int> dp;
    unordered_set<string> wds;
    int dfs(string word){
        if(dp.count(word))
            return dp[word];
        int ret = 1, n = word.size();
        for(int i = 0; i <= n; i++){
            for(char j = 'a'; j <= 'z'; j++){
                string newWord = word.substr(0, i);
                newWord.push_back(j);
                newWord += word.substr(i, n-i);
                if(wds.count(newWord)){
                    ret = max(ret, 1 + dfs(newWord));
                }
            }
        }
        return dp[word] = ret;
    }
public:
    int longestStrChain(vector<string>& words) {
        wds = unordered_set<string>(words.begin(), words.end());
        int ans = 1;
        for(auto &i: words)
            if(!dp.count(i))
                ans = max(ans, dfs(i));
        return ans;
    }
};