class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> charfrq(26);
        for(auto &i: chars)
            charfrq[i-'a']++;
        vector<vector<int>> frqs;
        for(auto &word: words){
            vector<int> frq(26);
            for(auto &i: word)
                frq[i-'a']++;
            bool yes = true;
            for(int i = 0; i < 26; i++){
                if(frq[i] > charfrq[i]){
                    yes = false;
                    break;
                }
            }
            if(yes)
                ans += word.size();
        }
        return ans;
    }
};