class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0, n = tokens.size(), score = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n-1;
        bool change = true;
        cout<<endl;
        while(i <= j && change && i < n){
            cout<<power<<" "<<score<<" "<<i<<" "<<j<<endl;
            change = false;
            while(i < n && power-tokens[i] >= 0){
                power -= tokens[i++];
                score++;
                change = true;
            }
            ans = max(score, ans);
            if(j >= 0 && score > 0){
                score--;
                power += tokens[j--];
                change = true;
            }
        }
        return ans;
    }
};