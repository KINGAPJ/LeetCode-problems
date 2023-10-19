class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sInd = 0, tInd = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#')
                sInd = max(sInd-1, 0);
            else{
                s[sInd++] = s[i];
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#')
                tInd = max(tInd-1, 0);
            else{
                t[tInd++] = t[i];
            }
        }
        if(tInd != sInd)
            return false;
        for(int i = 0; i < sInd; i++){
            if(s[i] != t[i])
                return false;
        }
        return true;
    }
};