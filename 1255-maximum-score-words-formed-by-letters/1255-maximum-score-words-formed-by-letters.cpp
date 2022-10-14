class Solution {
    vector<int> scor;
    vector<string> word;
    map<char, int> let;
    map<pair<int, map<char,int>>, int> memo;
public:
    int dp(int i, map<char, int> &let){
        int n = word.size();
        if(let.size() == 0 || i == n)
            return 0;
        if(memo.count(make_pair(i, let)))
            return memo[{i, let}];
        bool ok = true;
        map<char, int> temp = let;
        int curr = 0;
        // cout<<"i:"<<i<<endl;
        // for(auto &j: let)
        //     cout<<j.first<<":"<<j.second<<" ";
        // cout<<endl;
        for(int j = 0; j < word[i].size(); j++){
            if(let[word[i][j]] > 1){
                let[word[i][j]]--;
                curr += scor[word[i][j]-'a'];
                // cout<<j<<":"<<curr<<" ";
            }else if(let[word[i][j]] == 1){
                let.erase(word[i][j]);
                curr += scor[word[i][j]-'a'];
                // cout<<j<<":"<<curr<<" ";
            }else{
                ok = false;
                break;
            }
        }
        if(ok){
            int one = curr + dp(i+1, let);
            let = temp;
            int zero = dp(i+1, let);
            // cout<<i<<" "<<one<<" "<<zero<<endl;
            return memo[{i, let}] = max(one, zero);
        }else{
            let = temp;
            return memo[{i, let}] = dp(i+1, let);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        scor = score;
        word = words;
        for(auto &i: letters)
            let[i]++;
        return dp(0, let);
    }
};