class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, rem = 0;
        for(int i = 0; i < s.size(); i++){
            rem += s[i] == '(' ? 1 : -1;
            if(rem == -1){
                ans++;
                rem = 0;
            }
        }
        return ans + rem;
    }
};