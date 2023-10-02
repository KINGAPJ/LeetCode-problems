class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size();
        int Astreak = 0, Bstreak = 0;
        for(int i = 2; i < n; i++){
            if(s[i] == 'A' && s[i-1] == 'A' && s[i-2] == 'A')
                Astreak++;
            else if(s[i] == 'B' && s[i-1] == 'B' && s[i-2] == 'B')
                Bstreak++;
        }
        if(Astreak > Bstreak)
            return true;
        return false;
    }
};